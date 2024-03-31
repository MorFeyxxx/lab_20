#ifndef UNTITLED1_ALGORITHMS_H
#define UNTITLED1_ALGORITHMS_H

#include "../data_structures/matrix/matrix.h"

// меняет местами строки матрицы m, в которых находятся максимальный и минимальный элемент
void swap_min_max_rows(matrix* m);

// возвращает максимальный элемент массива a размера n
int get_max(const int a[], int n);

// сортирует строки матрицы по неубыванию наибольших элементов строк
void sort_rows_by_min_element(matrix* m);

// возвращает минимальный элемент массива a размера n
int get_min(const int *a, int n);

// сортирует столбцы матрицы по неубыванию наименьших элементов строк
void sort_cols_by_min_element(matrix *m);

// возвращает матрицу, равную перемножению матрицы m1 на матрицу m2
matrix mul_matrices(matrix m1, matrix m2);

// преобразует симметричную матрицу на её квадрат
void get_square_of_matrix_if_symmetric(matrix *m);

// возвращает true, если массив a размера n состоит только из уникальных элементов
// иначе false
bool is_unique(long long int a[], int n);

// возвращает сумму элементов массива a размера n
long long int get_sum(int a[], int n);

// транспонирует матрицу, если суммы строк различны
void transpose_if_matrix_has_not_equal_sum_of_rows(matrix* m);

// возвращает true, если матрицы m1 и m2 являются взаимно обратными
// иначе false
bool is_mutually_inverse_matrices(matrix m1, matrix m2);

// возвращает максимальный элемент между a и b
int max(int a, int b);

// возвращает сумму максимальных элементов псевдодиагоналей матрицы m
// только, если элементы матрицы положительны, иначе 0
long long find_sum_of_maxes_of_pseudo_diagonal(matrix m);

// возвращает true, если элемент по индексу i,j находится в области элемента max
bool value_in_area(position max, int i, int j);

// возвращает минимальный элемент матрицы m, который находится в зоне
int get_min_in_area(matrix m);

// возвращает расстояние вектора a размера n, до начала координат
float get_distance(int *a, int n);

// сортирует строки матрицы m, относительно их удалённости от начала координат
void sort_by_distances(matrix *m);

// компаратор
int cmp_long_long(const void *pa, const void *pb);

// возвращает количество уникальных элементов массива a размера n
int count_n_unique(long long *a, int n);

// возвращает количество уникальных сумм строк матрицы m
int count_eq_classes_by_rows_sum(matrix m);

// возвращает количество "особых" элементов матрицы m
// элемент считается особенным, если он больше суммы остальных элементов своего столбца
int get_n_special_element(matrix m);

// возвращает position минимального левого элемента
position get_left_min(matrix m);

// меняет местами предпоследнюю строку матрицы m, на n-ый столбец
void swap_penultimate_row(matrix* m, int n);

// возвращает true, если массив a размера n отсортирован по не убыванию
// иначе false
bool is_non_descending_sorted(const int *a, int n);

// возвращает true, если все строки матрицы m отсортированы по не убыванию
// иначе false
bool has_all_non_descending_rows(matrix m);

// возвращает количество матриц, из массива матриц ms размера n_matrix,
// строки в которых упорядочены по не убыванию
int count_non_descending_rows_matrices(matrix *ms, int n_matrix);

// возвращает количество элементов value в массиве a размера n
int count_values(const int *a, int n, int value);

// возвращает количество нулевых строк в матрицы m
int count_zero_rows(matrix m);

// выводит матрицы, из массива матриц ms размера n_matrix,
// с максимальным числом нулевых строк
void print_matrix_with_max_zero_rows(matrix *ms, int nMatrix);

// возвращает максимальное абсолютное значение в массиве a размера n
int get_max_abs_value(const int *a, int n);

// возвращает максимальное абсолютное значение в матрице m
int get_max_abs_value_in_matrix(matrix m);

// выводит матрицы, из массива матриц ms размера n_matrix,
// с минимальной нормой
// за норму берут максимум из абсолютных величин матрицы
void print_matrix_with_min_standard(matrix *ms, int n_matrix);

// возвращает true, если элемент по индексу index в массиве a размера n является особенным
// элемент особенный, если в строке слева от него находятся только меньшие элементы,
// иначе false
bool is_special_element(int *a, int n, int index);

// возвращает количество "особых" элементов матрицы m
// элемент считается особенным, если в строке слева от него находятся только меньшие элементы,
// а справа большие
int get_n_special_element_2(matrix m);

// возвращает скалярное произведение массива a размера n на массив b размера n
double get_scalar_product(int *a, int *b, int n);

// возвращает длину вектора a размера n
double get_vector_length(int *a, int n);

// возвращает косинус между вектором a размера n и вектором b размера n
double get_cosine(int *a, int *b, int n);

// возвращает индекс строки матрицы m, которая образует максимальный угол с данным вектором b
int get_vector_index_with_max_angle(matrix m, int* b);

#endif //UNTITLED1_ALGORITHMS_H
