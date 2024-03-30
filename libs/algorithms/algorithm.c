#include "algorithm.h"
#include <stdlib.h>
#include <math.h>

// 1
void swap_min_max_rows(matrix* m){
    position mx = getMaxValuePos(*m);
    position mn = getMinValuePos(*m);

    swapRows(m, mx.rowIndex, mn.rowIndex);
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

void get_square_of_matrix_if_symmetric(matrix *m){
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


// 5
bool is_unique(long long int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;

    return true;
}

long long int get_sum(int a[], int n) {
    long long int res = 0;

    for (int i = 0; i < n; i++)
        res += a[i];

    return res;
}

void transpose_if_matrix_has_not_equal_sum_of_rows(matrix* m) {
    long long int sum[m->nRows];

    for (int i = 0; i < m->nRows; i++)
        sum[i] = get_sum(m->values[i], m->nCols);

    if (is_unique(sum, m->nRows))
        transposeSquareMatrix(m);
}

// 6
bool is_mutually_inverse_matrices(matrix m1, matrix m2){
    matrix multi = mul_matrices(m1, m2);

    bool is_e_matrix = isEMatrix(&multi);

    freeMemMatrix(&multi);

    return is_e_matrix;
}


// 7
int max(int a, int b){
    return a > b ? a : b;
}

long long find_sum_of_maxes_of_pseudo_diagonal(matrix m){
    int r = m.nRows;
    int c = m.nCols;
    int* max_value = (int*) malloc(sizeof(int) * (r + c - 1));

    for (int i = 0; i < r + c - 1; i++)
        max_value[i] = 0;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (i != j)
                max_value[i - j + c - 1] = max(max_value[i - j + c - 1], m.values[i][j]);

    long long int sum = 0;
    for (int i = 0; i < r + c - 1; i++)
        sum += max_value[i];

    free(max_value);

    return sum;
}


// 8
bool value_in_area(position max, int i, int j) {
    position new_position = {i - max.rowIndex, j - max.colIndex};

    return (new_position.rowIndex <= new_position.colIndex) && (new_position.rowIndex <= -new_position.colIndex);
}

int get_min_in_area(matrix m) {
    position max = getMaxValuePos(m);

    int min = (int) 1e18;

    for (int i = 0; i <= max.rowIndex; i++)
        for (int j = 0; j < m.nCols; j++)
            if (value_in_area(max, i, j) && m.values[i][j] < min)
                min = m.values[i][j];

    return min;
}


// 8
float get_distance(int *a, int n){
    long long int square_sum = 0;

    for (int i = 0; i < n; i++)
        square_sum += a[i] * a[i];

    return sqrt(square_sum);
}

void insertion_sort_rows_matrix_by_row_criteria_F(matrix* m, float (*criteria)(int*, int)) {
    float res_criteria[m->nRows];

    for (size_t i = 0; i < m->nRows; i++)
        res_criteria[i] = criteria(m->values[i], m->nCols);

    int i, j;
    float key;
    int* address_key;
    for (i = 1; i < m->nRows; i++) {
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;

        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swapRows(m, j + 1, j);

            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}

void sort_by_distances(matrix *m){
    insertion_sort_rows_matrix_by_row_criteria_F(m, get_distance);
}


// 10
int cmp_long_long(const void* pa, const void* pb) {
    return (int)(*(long long int*) pa - *(long long int*) pb);
}

int count_n_unique(long long *a, int n){
    int amount = 1;

    int i = 0;
    while (i < n - 1) {
        if (a[i] != a[i + 1])
            amount++;

        i++;
    }

    return amount;
}

int count_eq_classes_by_rows_sum(matrix m){
    long long int values[m.nRows];

    for (int i = 0; i < m.nRows; i++)
        values[i] = get_sum(m.values[i], m.nCols);

    qsort(values, m.nRows, sizeof(long long int), cmp_long_long);

    int result = count_n_unique(values, m.nRows);

    return result;
}


// 11
int get_n_special_element(matrix m){
    int amount = 0;

    for (int i = 0; i < m.nCols; i++) {
        int sum = m.values[0][i];
        int max_values = m.values[0][i];

        for (int j = 1; j < m.nRows; j++) {
            sum += m.values[j][i];

            if (m.values[j][i] > max_values)
                max_values = m.values[j][i];
        }

        if (max_values > (sum - max_values))
            amount++;
    }

    return amount;
}
