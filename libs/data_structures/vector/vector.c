#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
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