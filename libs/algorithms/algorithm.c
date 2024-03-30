#include "algorithm.h"
#include <stdlib.h>

// 1
void swap_min_max_rows(matrix* m){
    position mx = getMaxValuePos(*m);
    position mn = getMinValuePos(*m);

    swapRows(*m, mx.rowIndex, mn.rowIndex);
}


// 2
int get_max(const int a[], int n){
    int max = a[0];

    for (size_t i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void sort_rows_by_min_element(matrix* m){
    insertionSortRowsMatrixByRowCriteria(m, get_max);
}


// 3
int get_min(const int *a, int n){
    int min = a[0];

    for (size_t i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

void sort_cols_by_min_element(matrix *m){
    selectionSortColsMatrixByColCriteria(m, get_min);
}


// 4
matrix mul_matrices(matrix m1, matrix m2){
    if (m1.nCols != m2.nRows) {
        fprintf(stderr, "The matrix is not square");
        exit(1);
    }

    matrix res = getMemMatrix(m1.nRows, m2.nRows);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            res.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                res.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }

    return res;
}

void get_Square_Of_Matrix_If_Symmetric(matrix *m){
    if (!isSymmetricMatrix(m)){
        fprintf(stderr, "The matrix is not symmetric");
        exit(1);
    }

    matrix res = mul_matrices(*m, *m);

    freeMemMatrix(m);

    m->values = res.values;
    m->nRows = res.nRows;
    m->nCols = res.nCols;
}
