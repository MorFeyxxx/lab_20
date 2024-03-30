#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
#include "../../data_structures/matrix/matrix.h"
#include "../../algorithms/algorithm.h"

matrix getMemMatrix(int nRows, int nCols){
    int** values = (int**) malloc(sizeof(int*) * nRows);

    for (size_t i = 0; i < nRows; i++)
        values[i] = (int*) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m){
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms + i);

    free(ms->values);
    ms->values = NULL;
    ms->nRows = 0;
    ms->nCols = 0;
}

void inputMatrix(matrix *m){
    for (int i = 0; i < m->nRows; i++){
        printf("input %d row:", i + 1);
        for (int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
    }
}

void inputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++){
        printf("input %d mitrix\n", i + 1);
        inputMatrix(ms + 1);
        printf("\n");
    }
}

void outputMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++){
        putchar(124);
        printf(" ");
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        putchar(124);
        printf("\n");
    }

    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(*(ms + i));
}

void swapRows(matrix *m, int i1, int i2){
    int* temp = m->values[i1];
    m->values[i1] = m->values[i2];
    m->values[i2] = temp;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapColumns(matrix m, int j1, int j2){
    for (int i = 0; i < m.nRows; i++)
        swap(&m.values[i][j1], &m.values[i][j2]);
}

void insertionSortRowsMatrixByRowCriteria(matrix *m, int (*criteria)(const int*, int)){
    int res_criteria[m->nRows];

    for (int i = 0; i < m->nRows; i++)
        res_criteria[i] = criteria(m->values[i], m->nCols);

    int i, j, key;
    int* address_key;
    for (i = 1; i< m->nRows; i++){
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;

        while (j >= 0 && res_criteria[j] > key){
            res_criteria[j + 1] = res_criteria[j];
            swapRows(m, j + 1, j);
            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}

void selectionSortColsMatrixByColCriteria(matrix *m, int (*criteria)(const int*, int)){
    int res_criteria[m->nCols];

    for (int i = 0; i < m->nCols; i++){
        int temp[m->nRows];
        for (int j = 0; j < m->nRows; j++)
            temp[j] = m->values[j][i];

        res_criteria[i] = criteria(temp, m->nRows);
    }

    int value_min_index;
    for (int i = 0; i < m->nCols; i++){
        value_min_index = i;

        for (int j = i + 1; j < m->nCols; j++)
            if (res_criteria[j] < res_criteria[value_min_index])
                value_min_index = j;

        swap(&res_criteria[value_min_index], &res_criteria[i]);
        swapColumns(*m, value_min_index, i);
    }
}

bool isSquareMatrix(matrix *m){
    return m->nRows == m->nCols;
}

bool areTwoMatricesEqual(matrix *m1, matrix *m2){
    for (size_t i = 0; i < m1->nRows; i++)
        if (memcmp(m1->values[i], m2->values[i], m1->nCols) != 0)
            return false;

    return true;
}

bool isEMatrix(matrix *m){
    for (size_t i = 0; i < m->nRows; i++)
        for (size_t j = 0; j < m->nCols; j++)
            if ((j != i && m->values[i][j] != 0) || (j == i && m->values[i][j] != 1))
                return false;

    return true;
}

bool isSymmetricMatrix(matrix *m){
    for (size_t i = 0; i < m->nRows; i++)
        for (size_t j = i + 1; j < m->nCols; j++)
            if (m->values[i][j] != m->values[j][i])
                return false;

    return true;
}

void transposeSquareMatrix(matrix *m){
    if (m->nRows != m->nCols) {
        fprintf(stderr, "Is not square matrix");
        exit(1);
    }

    for (size_t i = 0; i < m->nRows; i++)
        for (size_t j = i + 1; j < m->nCols; j++)
            if (i != j)
                swap(&m->values[i][j], &m->values[j][i]);
}

void transposeMatrix(matrix *m){
    int** new_value = (int**) malloc(sizeof(int*) * m->nCols);

    for (size_t i = 0; i < m->nCols; i++) {
        new_value[i] = (int*) malloc(sizeof(int) * m->nRows);

        for (size_t j = 0; j < m->nRows; j++)
            new_value[i][j] = m->values[j][i];
    }

    for (size_t i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);

    m->values = new_value;
    swap(&m->nRows, &m->nCols);
}

position getMinValuePos(matrix m){
    int min_value = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < min_value) {
                min_value = m.values[i][j];
                pos.rowIndex = i;
                pos.colIndex = j;
            }

    return pos;
}

position getMaxValuePos(matrix m){
    int max_value = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > max_value) {
                max_value = m.values[i][j];
                pos.rowIndex = i;
                pos.colIndex = j;
            }

    return pos;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols){
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols){
    matrix* ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (size_t k = 0; k < nMatrices; k++)
        for (size_t i = 0; i < nRows; i++)
            for (size_t j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}