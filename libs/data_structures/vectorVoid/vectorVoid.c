#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <memory.h>
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

bool isEmptyV(vectorVoid *v){
    return v->size == 0;
}

bool isFullV(vectorVoid *v){
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination){
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source){
    if (index >= v->capacity) {
        fprintf(stderr, "IndexError: a[%lld] is not exists", index);
        exit(1);
    }

    char *address_element = (char *) v->data + index * v->baseTypeSize;
    memcpy(address_element, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v){
    if (isEmptyV(v)) {
        fprintf(stderr, "Zero length");
        exit(1);
    }

    v->size--;
}

void pushBackV(vectorVoid *v, void *source){
    if (isFullV(v)) {
        size_t new_capacity;

        if (isEmptyV(v))
            new_capacity = 1;
        else
            new_capacity = v->capacity * 2;

        reserveV(v, new_capacity);
    }

    setVectorValueV(v, v->size, source);
    v->size++;
}
