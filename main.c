#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vectorVoid.h"

// тест на работоспособность функции create
void test_createVector_non_empty_vector(){
    vector v = createVector(5);

    assert(v.data != NULL && v.size == 0 && v.capacity == 5);

    deleteVector(&v);
}

void test_createVector_empty_vector(){
    vector v = createVector(0);

    assert(v.size == 0 && v.capacity == 0);

    deleteVector(&v);
}

void test_createVector(){
    test_createVector_non_empty_vector();
    test_createVector_empty_vector();
}

// тест на изменение размера вектора
void test_reserve(){
    vector v = createVector(5);

    reserve(&v, 10);
    assert(v.capacity == 10);

    reserve(&v, 7);
    assert(v.capacity == 7);

    reserve(&v, 0);
    assert(v.capacity == 0);

    deleteVector(&v);
}

// тест на добавление в конец вектора элемент
void test_pushBack_non_empty_vector() {
    vector v = createVector(6);

    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);
    assert(v.size == 5);

    deleteVector(&v);
}

void test_pushBack_empty_vector() {
    vector v = createVector(5);

    pushBack(&v, 5);
    assert(v.data[0] == 5 && v.size == 1);

    deleteVector(&v);
}

void test_pushBack_zero_length() {
    vector v = createVector(0);

    pushBack(&v, 5);
    assert(v.data[0] == 5 && v.size == 1 && v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack(){
    test_pushBack_non_empty_vector();
    test_pushBack_empty_vector();
    test_pushBack_zero_length();
}

// тест на освобождение памяти, выделенную под неиспользуемые элементы
void test_shrinkToFit(){
    vector v = createVector(7);

    for (int i = 1; i < 6; i++)
        pushBack(&v, i);

    shrinkToFit(&v);
    assert(v.capacity == v.size);

    deleteVector(&v);
}

// тест на удаление последнего элемента
void test_pop_back() {
    vector v = createVector(0);

    pushBack(&v, 3);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVector(&v);
}

// тест на получение адреса i-го элемента вектора
void test_at_vector_non_empty_vector() {
    vector v = createVector(5);

    pushBack(&v, 6);
    pushBack(&v, 4);
    pushBack(&v, 8);

    int* ptr = atVector(&v, 1);
    assert(v.data[1] == *ptr);

    deleteVector(&v);
}
void test_at_vector_request_to_last_element() {
    vector v = createVector(4);

    pushBack(&v, 1);
    pushBack(&v, 3);
    pushBack(&v, 8);
    pushBack(&v, 6);

    int* ptr = back(&v);
    assert(v.data[3] == *ptr);

    deleteVector(&v);
}

void test_at_vector_request_to_first_element() {
    vector v = createVector(4);

    pushBack(&v, 1);
    pushBack(&v, 3);
    pushBack(&v, 8);
    pushBack(&v, 6);

    int* ptr = front(&v);
    assert(v.data[0] == *ptr);

    deleteVector(&v);
}

void test_at_vector() {
    test_at_vector_non_empty_vector();
    test_at_vector_request_to_last_element();
    test_at_vector_request_to_first_element();
}

// тест на работоспособность функции create
void test_createVectorV_int(){
    vectorVoid v = createVectorV(5, sizeof(int));

    assert(v.data != NULL && v.size == 0 && v.capacity == 5);

    deleteVectorV(&v);
}

void test_createVectorV_float_zero_length(){
    vectorVoid v = createVectorV(0, sizeof(float));

    assert(v.size == 0 && v.capacity == 0);

    deleteVectorV(&v);
}

void test_createVectorV(){
    test_createVectorV_int();
    test_createVectorV_float_zero_length();
}

// тест на изменение размера вектора
void test_reserveV(){
    vectorVoid v = createVectorV(5, sizeof(int));

    reserveV(&v, 10);
    assert(v.capacity == 10);

    reserveV(&v, 7);
    assert(v.capacity == 7);

    reserveV(&v, 0);
    assert(v.capacity == 0);

    deleteVectorV(&v);
}

// тест на добавление в конец вектора элемент
void test_pushBackV_non_empty_vector_int() {
    vectorVoid v = createVectorV(6, sizeof(int));

    int x[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++){
        pushBackV(&v, x + i);
    }

    for (int i = 0; i < 3; i++){
        int value;
        getVectorValueV(&v, i, &value);

        assert(value == x[i]);
    }

    deleteVectorV(&v);
}

void test_pushBackV_non_empty_vector_float() {
    vectorVoid v = createVectorV(6, sizeof(float));

    float x[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++){
        pushBackV(&v, x + i);
    }

    for (int i = 0; i < 3; i++){
        float value;
        getVectorValueV(&v, i, &value);

        assert(fabs(value - x[i]) < 0.0001);
    }

    deleteVectorV(&v);
}

void test_pushBackV_empty_vector() {
    vectorVoid v = createVectorV(5, sizeof(int));

    int x = 5;
    pushBackV(&v, &x);

    int value;
    getVectorValueV(&v, 0, &value);

    assert(value == x && v.size == 1 && v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_pushBackV_zero_length() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 5;
    pushBackV(&v, &x);

    int value;
    getVectorValueV(&v, 0, &value);

    assert(value == x && v.size == 1 && v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_pushBackV(){
    test_pushBackV_non_empty_vector_int();
    test_pushBackV_non_empty_vector_float();
    test_pushBackV_empty_vector();
    test_pushBack_zero_length();
}

// тест на освобождение памяти, выделенную под неиспользуемые элементы
void test_shrinkToFitV(){
    vectorVoid v = createVectorV(7, sizeof(int));

    int x = 5;
    for (int i = 1; i < 5; i++)
        pushBackV(&v, &x);

    shrinkToFitV(&v);
    assert(v.capacity == v.size);

    deleteVectorV(&v);
}

// тест на удаление последнего элемента
void test_popBackV() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 3;
    pushBackV(&v, &x);
    assert(v.size == 1);

    popBackV(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVectorV(&v);
}

void test(){
    test_createVector();
    test_reserve();
    test_pushBack();
    test_shrinkToFit();
    test_pop_back();
    test_at_vector();
    test_createVectorV();
    test_reserveV();
    test_pushBack();
    test_shrinkToFitV();
    test_pop_back();
}

int main() {
    test();

    return 0;
}

