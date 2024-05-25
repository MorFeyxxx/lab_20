#ifndef UNTITLED1_2_GAME_OF_LIFE_H
#define UNTITLED1_2_GAME_OF_LIFE_H

#include "../../data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdbool.h>


int is_point_alive(matrix *m, int i, int j) {
    bool is_alive = m->values[i][j];

    int high_i = i > 0 ? i - 1 : i;
    int down_i = i < m->nRows - 1 ? i + 1 : i;
    int left_j = j > 0 ? j - 1 : j;
    int right_j = j < m->nCols - 1 ? j + 1 : j;

    int amount_units = 0;
    for (int row_i = high_i; row_i <= down_i; row_i++)
        for (int col_j = left_j; col_j <= right_j; col_j++)
            if (m->values[row_i][col_j] && (row_i != i || col_j != j))
                amount_units++;

    if (is_alive && (amount_units < 2))
        return 0;

    if (is_alive && (amount_units == 2 || amount_units == 3))
        return 1;

    if (is_alive && amount_units > 3)
        return 0;

    if (!is_alive && amount_units == 3)
        return 1;

    return 0;
}


void game_life(const char* filename) {
    FILE* file = fopen(filename, "rb");
    int n, m;
    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);

    matrix mat = getMemMatrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fread(&mat.values[i][j], sizeof(int), 1, file);

    matrix res_mat = getMemMatrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res_mat.values[i][j] = is_point_alive(&mat, i, j);

    fclose(file);


    file = fopen(filename, "wb");

    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fwrite(&res_mat.values[i][j], sizeof(int), 1, file);

    freeMemMatrix(&mat);
    freeMemMatrix(&res_mat);

    fclose(file);
}


void test_game_life_1_empty_file() {
    const char filename[] = "F:\\laba_op_20\\task_2\\test_1.txt";

    FILE* file = fopen(filename, "wb");

    int n = 0;
    int m = 0;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);

    fclose(file);


    game_life(filename);


    file = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);

    assert(n == 0);
    assert(m == 0);

    fclose(file);
}


void test_game_life_2_unit_file() {
    const char filename[] = "F:\\laba_op_20\\task_2\\test_1.txt";

    FILE* file = fopen(filename, "wb");

    int n = 1;
    int m = 1;
    int x = 0;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);
    fwrite(&x, sizeof(int), 1, file);

    fclose(file);


    game_life(filename);


    file = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);
    fread(&x, sizeof(int), 1, file);

    assert(n == 1);
    assert(m == 1);
    assert(x == 0);

    fclose(file);
}


void test_game_life_3_more_elements() {
    const char filename[] = "F:\\laba_op_20\\task_2\\test_1.txt";

    FILE* file = fopen(filename, "wb");

    int n = 4;
    int m = 3;
    fwrite(&n, sizeof(int), 1, file);
    fwrite(&m, sizeof(int), 1, file);

    matrix mat = createMatrixFromArray((int[]) {0, 1,  0,
                                                   0, 0,  1,
                                                   1, 1,  1,
                                                   0, 0, 0}, n, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fwrite(&mat.values[i][j], sizeof(int), 1, file);

    fclose(file);


    game_life(filename);


    file = fopen(filename, "rb");

    fread(&n, sizeof(int), 1, file);
    fread(&m, sizeof(int), 1, file);

    matrix res = getMemMatrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fread(&res.values[i][j], sizeof(int), 1, file);

    matrix check = createMatrixFromArray((int[]) {0, 0, 0,
                                                     1, 0, 1,
                                                     0, 1, 1,
                                                     0, 1, 0}, n, m);


    assert(n == 4);
    assert(m == 3);
    assert(areTwoMatricesEqual(&res, &check));

    freeMemMatrix(&mat);
    freeMemMatrix(&res);
    freeMemMatrix(&check);
    fclose(file);
}


void test_2_game_life() {
    test_game_life_1_empty_file();
    test_game_life_2_unit_file();
    test_game_life_3_more_elements();
}


#endif //UNTITLED1_2_GAME_OF_LIFE_H
