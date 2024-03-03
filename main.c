#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vectorVoid.h"

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

void test_pushBack_zero_length() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 5;
    pushBackV(&v, &x);

    int value;
    getVectorValueV(&v, 0, &value);

    assert(value == x && v.size == 1 && v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_pushBack(){
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
void test_pop_back() {
    vectorVoid v = createVectorV(0, sizeof(int));

    int x = 3;
    pushBackV(&v, &x);
    assert(v.size == 1);

    popBackV(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVectorV(&v);
}

void test(){
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

