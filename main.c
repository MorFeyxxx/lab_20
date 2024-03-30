#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

void test_swap_min_max_rows_1_standard_swap() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {7, 8, 9,
                                                     4, 5, 6,
                                                     1, 2, 3},3, 3);

    swap_min_max_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows_2_min_and_max_elements_equal() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                                 1, 1, 1,
                                                 1, 1, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                     1, 1, 1,
                                                     1, 1, 1},3, 3);

    swap_min_max_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows_3_min_and_max_elements_in_one_row() {
    matrix m = createMatrixFromArray((int[]) {1, 7, 1,
                                                 1, 1, 1,
                                                 1, 1, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 7, 1,
                                                     1, 1, 1,
                                                     1, 1, 1},3, 3);

    swap_min_max_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_min_max_rows() {
    test_swap_min_max_rows_1_standard_swap();
    test_swap_min_max_rows_2_min_and_max_elements_equal();
    test_swap_min_max_rows_3_min_and_max_elements_in_one_row();
}


void test_sort_rows_by_max_element_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                                 1, 8, 1,
                                                 3, 2, 3}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {3, 2, 3,
                                                     7, 1, 2,
                                                     1, 8, 1},3, 3);

    sort_rows_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_rows_by_max_element_2_max_value_equal() {
    matrix m = createMatrixFromArray((int[]) {8, 2, 3,
                                                 2, 8, 2,
                                                 4, 8, 8}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {8, 2, 3,
                                                     2, 8, 2,
                                                     4, 8, 8},3, 3);


    sort_rows_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_rows_by_max_element() {
    test_sort_rows_by_max_element_1_standard_value();
    test_sort_rows_by_max_element_2_max_value_equal();
}


void test_sort_cols_by_min_element_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                                 2, 5, 1, 8, 2, 7,
                                                 6, 1, 4, 4, 8, 3}, 3, 6);

    matrix check = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                     5, 1, 2, 2, 7, 8,
                                                     1, 4, 6, 8, 3, 4},3, 6);

    sort_cols_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_cols_by_min_element_2_min_value_equal() {
    matrix m = createMatrixFromArray((int[]) {4, 6, 3, 2, 4, 4,
                                                 2, 6, 2, 9, 2, 8,
                                                 7, 2, 5, 5, 9, 2}, 3, 6);

    matrix check = createMatrixFromArray((int[]) {4, 6, 3, 2, 4, 4,
                                                     2, 6, 2, 9, 2, 8,
                                                     7, 2, 5, 5, 9, 2},3, 6);

    sort_cols_by_min_element(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_sort_cols_by_min_element() {
    test_sort_cols_by_min_element_1_standard_value();
    test_sort_cols_by_min_element_2_min_value_equal();
}


void test_mul_matrices_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                  2, 1, 2,
                                                  3, 2, 1}, 3, 3);

    matrix result = mul_matrices(m, m);

    matrix check = createMatrixFromArray((int[]) {14, 10, 10,
                                                     10, 9, 10,
                                                     10, 10, 14}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mul_matrices_2_mul_to_e_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0,
                                                  0, 0, 1}, 3, 3);

    matrix result = mul_matrices(m, m);


    matrix check = createMatrixFromArray((int[]) {1, 0, 0,
                                                     0, 1, 0,
                                                     0, 0, 1}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}

void test_mul_matrices_3_mul_to_null_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {0, 0, 0,
                                                  0, 0, 0,
                                                  0, 0, 0}, 3, 3);

    matrix result = mul_matrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {0, 0, 0,
                                                     0, 0, 0,
                                                     0, 0, 0}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mul_matrices() {
    test_mul_matrices_1_standard_value();
    test_mul_matrices_2_mul_to_e_matrix();
    test_mul_matrices_3_mul_to_null_matrix();
}

void test(){
    test_swap_min_max_rows();
    test_sort_rows_by_max_element();
    test_sort_cols_by_min_element();
    test_mul_matrices();
}

int main() {
    test();

    return 0;
}

