#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../algorithms/array/array.h"
#include "../../data_structures/vector/vector.h"


vector createVector(size_t capacity){
    int *data = malloc(sizeof(int) * capacity);

    if (data == NULL){
        printf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data, 0, capacity};
}

void reserve(vector *v, size_t newCapacity){
    if (newCapacity > 0){
        int *data = realloc(v->data, sizeof(int) * newCapacity);

        if (data == NULL){
            printf(stderr, "bad alloc");
            exit(1);
        }

        v->data = data;
        v->capacity = newCapacity;

        if (v->size > newCapacity)
            v->size = newCapacity;
    } else
        deleteVector(v);
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v){
    return v->size == 0;
}

bool isFull(vector *v){
    return v->size == v->capacity;
}

int getVectorValue(vector v, size_t i){
    return v.data[i];
}

void pushBack(vector *v, int x){
    if (isFull(v)) {
        size_t new_capacity;

        if (isEmpty(v))
            new_capacity = 1;
        else
            new_capacity = v->capacity * 2;

        reserve(v, new_capacity);
    }

    v->size++;
    v->data[v->size - 1] = x;

}

void popBack(vector *v){
    if (isEmpty(v)){
        printf(stderr, "Zero length");
        exit(1);
    }

    v->size--;
}

int* atVector(vector *v, size_t index){
    if (index > v->capacity){
        printf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }

    return &v->data[index];
}

int* back(vector *v){
    if (isEmpty(v)){
        printf(stderr, "Zero length");
        exit(1);
    }

    return &v->data[v->size - 1];
}

int* front(vector *v){
    if (isEmpty(v)){
        printf(stderr, "Zero length");
        exit(1);
    }

    return &v->data[0];
}

void popBackIndex(vector *v, int index){
    if (isEmpty(v)){
        printf(stderr, "Zero length");
        exit(1);
    }

    for(int i = index; i < v->size - 1; i++)
        v->data[i] = v->data[i + 1];
}