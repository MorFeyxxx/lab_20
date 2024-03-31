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

    get_square_of_matrix_if_symmetric(&m);

    matrix check = createMatrixFromArray((int[]) {14, 10, 10,
                                                     10, 9, 10,
                                                     10, 10, 14}, 3, 3);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_mul_matrices_2_mul_to_e_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0,
                                                  0, 0, 1}, 3, 3);

    get_square_of_matrix_if_symmetric(&m);


    matrix check = createMatrixFromArray((int[]) {1, 0, 0,
                                                     0, 1, 0,
                                                     0, 0, 1}, 3, 3);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&m);
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


void test_transpose_if_matrix_has_not_equal_sum_of_rows_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 4, 7,
                                                     2, 5, 8,
                                                     3, 6, 9}, 3, 3);

    transpose_if_matrix_has_not_equal_sum_of_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_transpose_if_matrix_has_not_equal_sum_of_rows_2_not_different_sum() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 1,
                                                 2, 1, 2,
                                                 0, 0, 2}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 0, 1,
                                                     2, 1, 2,
                                                     0, 0, 2}, 3, 3);

    transpose_if_matrix_has_not_equal_sum_of_rows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_transpose_if_matrix_has_not_equal_sum_of_rows() {
    test_transpose_if_matrix_has_not_equal_sum_of_rows_1_standard_value();
    test_transpose_if_matrix_has_not_equal_sum_of_rows_2_not_different_sum();
}


void test_is_mutually_inverse_matrices_1_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 1,
                                                  2, 1}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {-1, 1,
                                                  2, -1}, 2, 2);

    bool result = is_mutually_inverse_matrices(m1, m2);

    assert(result == 1);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_is_mutually_inverse_matrices_2_not_inverse_matrices() {
    matrix m1 = createMatrixFromArray((int[]) {1, 1,
                                                  1, 4}, 2, 2);

    matrix m2 = createMatrixFromArray((int[]) {6, 1,
                                                  4, -3}, 2, 2);

    bool result = is_mutually_inverse_matrices(m1, m2);

    assert(result == 0);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_is_mutually_inverse_matrices() {
    test_is_mutually_inverse_matrices_1_inverse_matrices();
    test_is_mutually_inverse_matrices_2_not_inverse_matrices();
}


void test_find_sum_of_maxes_of_pseudo_diagonal_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {4, 3, 6, 5,
                                                 2, 4, 7, 4,
                                                 4, 3, 2, 3}, 3, 4);

    long long int result = find_sum_of_maxes_of_pseudo_diagonal(m);

    assert(result == 25);

    freeMemMatrix(&m);
}

void test_find_sum_of_maxes_of_pseudo_diagonal_2_one_element() {
    matrix m = createMatrixFromArray((int[]) {7}, 1, 1);

    long long int result = find_sum_of_maxes_of_pseudo_diagonal(m);

    assert(result == 0);

    freeMemMatrix(&m);
}

void test_find_sum_of_maxes_of_pseudo_diagonal() {
    test_find_sum_of_maxes_of_pseudo_diagonal_1_standard_value();
    test_find_sum_of_maxes_of_pseudo_diagonal_2_one_element();
}


void test_get_min_in_area_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                                 3, 11, 8, 9,
                                                 4, 1, 12, 2}, 3, 4);

    int result = get_min_in_area(m);

    assert(result == 5);

    freeMemMatrix(&m);
}

void test_get_min_in_area_2_max_value_in_first_row() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 12, 6,
                                                 3, 11, 8, 9,
                                                 4, 1, 5, 2}, 3, 4);

    int result = get_min_in_area(m);

    assert(result == 12);

    freeMemMatrix(&m);
}

void test_get_min_in_area_3_equal_element() {
    matrix m = createMatrixFromArray((int[]) {0, 0,
                                                 0, 0}, 2, 2);

    int result = get_min_in_area(m);

    assert(result == 0);

    freeMemMatrix(&m);
}

void test_get_min_in_area() {
    test_get_min_in_area_1_standard_value();
    test_get_min_in_area_2_max_value_in_first_row();
    test_get_min_in_area_3_equal_element();
}


void test_sort_by_distance_1_different_distance() {
    matrix v = createMatrixFromArray((int[]) {2, 2, 2,
                                                 3, 3, 3,
                                                 1, 1, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                     2, 2, 2,
                                                     3, 3, 3}, 3, 3);

    sort_by_distances(&v);

    assert(areTwoMatricesEqual(&v, &check));

    freeMemMatrix(&v);
    freeMemMatrix(&check);
}

void test_sort_by_distance_2_equal_distance() {
    matrix v = createMatrixFromArray((int[]) {1, 2, 3,
                                                 2, 1, 3,
                                                 3, 1, 2}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                     2, 1, 3,
                                                     3, 1, 2}, 3, 3);

    sort_by_distances(&v);

    assert(areTwoMatricesEqual(&v, &check));

    freeMemMatrix(&v);
    freeMemMatrix(&check);
}

void test_sort_by_distance() {
    test_sort_by_distance_1_different_distance();
    test_sort_by_distance_2_equal_distance();
}


void test_count_eq_classes_by_rows_sum_1_different_sum() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                                 2, 7,
                                                 5, 4,
                                                 4, 3,
                                                 1, 6,
                                                 8, 0}, 6, 2);

    int result = count_eq_classes_by_rows_sum(m);

    assert(result == 3);

    freeMemMatrix(&m);
}

void test_count_eq_classes_by_rows_sum_2_all_sum_different() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              5, 7,
                                              5, 4,}, 3, 2);

    int result = count_eq_classes_by_rows_sum(m);

    assert(result == 3);

    freeMemMatrix(&m);
}

void test_count_eq_classes_by_rows_sum_3_equal_sum() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              5, 3,
                                              4, 4,}, 3, 2);

    int result = count_eq_classes_by_rows_sum(m);

    assert(result == 1);

    freeMemMatrix(&m);
}

void test_count_eq_classes_by_rows_sum() {
    test_count_eq_classes_by_rows_sum_1_different_sum();
    test_count_eq_classes_by_rows_sum_2_all_sum_different();
    test_count_eq_classes_by_rows_sum_3_equal_sum();
}


void test_get_n_special_element_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                                 2, 3, 6, 7,
                                                 12, 2, 1, 2}, 3, 4);

    int result = get_n_special_element(m);

    assert(result == 2);

    freeMemMatrix(&m);
}

void test_get_n_special_element_2_not_have_special_element() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                                 2, 3, 6, 7,
                                                 3, 2, 1, 7}, 3, 4);

    int result = get_n_special_element(m);

    assert(result == 0);

    freeMemMatrix(&m);
}

void test_get_n_special_element() {
    test_get_n_special_element_1_standard_value();
    test_get_n_special_element_2_not_have_special_element();
}


void test_swap_penultimate_row_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                     1, 4, 7,
                                                     7, 8, 1}, 3, 3);

    position min = get_left_min(m);

    swap_penultimate_row(&m, min.colIndex);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_penultimate_row_2_one_row() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3}, 1, 3);

    swap_penultimate_row(&m, 0);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}

void test_swap_penultimate_row() {
    test_swap_penultimate_row_1_standard_value();
    test_swap_penultimate_row_2_one_row();
}


void test_count_non_descending_rows_matrices_standard_value() {
    matrix *ms = createArrayOfMatrixFromArray((int[]){7, 1, 1, 1,
                                                            1, 6, 2, 2,
                                                            5, 4 ,2, 3,
                                                            1, 3,7, 9},
                                              4, 2, 2);

    int res = count_non_descending_rows_matrices(ms, 4);

    assert(res == 2);

    freeMemMatrices(ms, 4);
}

void test_count_non_descending_rows_matrices_one_col() {
    matrix *ms = createArrayOfMatrixFromArray((int[]){7, 1,
                                                            1, 1,
                                                            1, 6,
                                                            2, 2}, 4, 2, 1);

    int res = count_non_descending_rows_matrices(ms, 4);

    assert(res == 4);

    freeMemMatrices(ms, 4);
}

void test_count_non_descending_rows_matrices() {
    test_count_non_descending_rows_matrices_standard_value();
    test_count_non_descending_rows_matrices_one_col();
}


void test_print_matrix_with_max_zero_rows_standard_value(){
    matrix *ms = createArrayOfMatrixFromArray((int[]){0, 1, 1, 0, 0, 0,
                                                            1, 1, 2, 1, 1, 1,
                                                            0, 0, 0, 0, 4, 7},
                                              3, 3, 2);

    print_matrix_with_max_zero_rows(ms, 3);

    freeMemMatrices(ms, 3);
}

void test_print_matrix_with_max_zero_rows_non_zero_rows(){
    matrix *ms = createArrayOfMatrixFromArray((int[]){1, 1, 2, 2,
                                                            2, 2, 3, 3,
                                                            3, 3, 4, 4},
                                                        3, 2, 2);

    print_matrix_with_max_zero_rows(ms, 3);

    freeMemMatrices(ms, 3);
}

void test_print_matrix_with_max_zero_rows() {
    test_print_matrix_with_max_zero_rows_standard_value();
    test_print_matrix_with_max_zero_rows_non_zero_rows();
}

void test_print_matrix_with_min_standard_standard_value(){
    matrix *ms = createArrayOfMatrixFromArray((int[]){0, 1, 2, 3,
                                                            0, -1, -2, -3,
                                                            -2, -1, 1, 2},
                                              3, 2, 2);

    print_matrix_with_min_standard(ms, 3);

    freeMemMatrices(ms, 3);
}

void test_print_matrix_with_min_standard() {
    test_print_matrix_with_min_standard_standard_value();
}


void test(){
    test_swap_min_max_rows();
    test_sort_rows_by_max_element();
    test_sort_cols_by_min_element();
    test_mul_matrices();
    test_transpose_if_matrix_has_not_equal_sum_of_rows();
    test_is_mutually_inverse_matrices();
    test_find_sum_of_maxes_of_pseudo_diagonal();
    test_get_min_in_area();
    test_sort_by_distance();
    test_count_eq_classes_by_rows_sum();
    test_get_n_special_element();
    test_swap_penultimate_row();
    test_count_non_descending_rows_matrices();
    //test_print_matrix_with_max_zero_rows();
    //test_print_matrix_with_min_standard();
}

int main() {
    test();

    return 0;
}

