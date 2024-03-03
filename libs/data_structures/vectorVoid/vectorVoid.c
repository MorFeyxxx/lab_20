#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../algorithms/array/array.h"
#include "../../data_structures/vectorVoid/vectorVoid.h"

vectorVoid createVectorV(size_t capacity, size_t baseTypeSize){
    int *data = malloc(baseTypeSize * capacity);

    if (data == NULL){
        printf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {data, 0, capacity, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if (newCapacity > 0){
        int *data = realloc(v->data, v->baseTypeSize * newCapacity);

        if (data == NULL){
            printf(stderr, "bad alloc");
            exit(1);
        }

        v->data = data;
        v->capacity = newCapacity;

        if (v->size > newCapacity)
            v->size = newCapacity;
    } else
        deleteVectorV(v);
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v, v->size);
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void deleteVectorV(vectorVoid *v){
    free(v->data);

    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}
