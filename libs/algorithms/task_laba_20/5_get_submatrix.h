#ifndef UNTITLED1_5_GET_SUBMATRIX_H
#define UNTITLED1_5_GET_SUBMATRIX_H

#include <stdlib.h>
#include <assert.h>

#include "../../data_structures/matrix/matrix.h"


int get_submatrix(matrix mat) {
    int m = mat.nRows;
    int n = mat.nCols;
    int res = 0;

    for (int i = 1; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat.values[i][j])
                mat.values[i][j] += mat.values[i - 1][j];

    for (int i = 0; i < m; i++) {
        int stack[n];
        int top = -1;
        int sums[n + 1];
        sums[0] = 0;

        for (int j = 0; j < n; j++) {
            while (top != -1 && mat.values[i][stack[top]] >= mat.values[i][j])
                top--;
            if (top != -1) {
                int k = stack[top];
                sums[j + 1] = sums[k + 1] + mat.values[i][j] * (j - k);
            } else
                sums[j + 1] = mat.values[i][j] * (j + 1);
            stack[++top] = j;
        }

        for (int j = 0; j <= n; j++)
            res += sums[j];
    }

    return res;
}


void test_get_submatrix_1_empty_matrix() {
    matrix m = createMatrixFromArray((int[]) {}, 0, 0);

    int result = get_submatrix(m);

    freeMemMatrix(&m);

    assert(result == 0);
}


void test_get_submatrix_2_unit_matrix() {
    matrix m = createMatrixFromArray((int[]) {1}, 1, 1);

    int result = get_submatrix(m);

    freeMemMatrix(&m);

    assert(result == 1);
}


void test_get_submatrix_3_more_element() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 1,
                                                 1, 1, 0,
                                                 1, 1, 0}, 3, 3);

    int result = get_submatrix(m);

    freeMemMatrix(&m);

    assert(result == 13);
}


void test_5_get_submatrix() {
    test_get_submatrix_1_empty_matrix();
    test_get_submatrix_2_unit_matrix();
    test_get_submatrix_3_more_element();
}

#endif //UNTITLED1_5_GET_SUBMATRIX_H
