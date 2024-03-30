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
void get_Square_Of_Matrix_If_Symmetric(matrix *m);


#endif //UNTITLED1_ALGORITHMS_H
