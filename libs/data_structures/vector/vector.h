#ifndef UNTITLED1_VECTOR_H
#define UNTITLED1_VECTOR_H

#include <stdbool.h>
#include <stdint.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//Возвращает структуру-дескриптор вектора из n значений
vector createVector(size_t n);

//Изменяет кол-во памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

//Удаляет элементы из контейнера, но не освобождает выделенную память
void clear(vector *v);

//Освобождает память, выделенную под неиспользуемые элементы
void shrinkToFit(vector *v);

//Освобождает память, выделенную вектору
void deleteVector(vector *v);

//Проверка на то, является ли вектор пустым
bool isEmpty(vector *v);

//Проверка на то, является ли вектор полным
bool isFull(vector *v);

//Возвращает i-ый элемент вектора v
int getVectorValue(vector v, size_t i);

//Добавляет элемент x в конец вектора v
void pushBack(vector *v, int x);

//Удаляет последный элемент из вектора
void popBack(vector *v);

//Возвращает указатель на index-ый элемент вектора
int* atVector(vector *v, size_t index);

//Возвращает указатель на последный элемент вектора
int* back(vector *v);

//Возвращает указатель на нулевой элемент вектора
int* front(vector *v);

// Удаляет элемент под индексом index с сохранением порядка, и без изменения размера
void popBackIndex(vector *v, int index);
#endif //UNTITLED1_VECTOR_H
