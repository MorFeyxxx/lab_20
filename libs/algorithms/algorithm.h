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


#endif //UNTITLED1_ALGORITHMS_H
