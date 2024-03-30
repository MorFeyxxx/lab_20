#include "algorithm.h"

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
