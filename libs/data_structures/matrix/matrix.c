#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "../../data_structures/matrix/matrix.h"
#include "../../algorithms/algorithm.h"

matrix getMemMatrix(int nRows, int nCols){
    int** values = (int**) malloc(sizeof(int*) * nRows);

    for (size_t i = 0; i < nRows; i++)
        values[i] = (int*) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m){
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms + i);

    free(ms->values);
    ms->values = NULL;
    ms->nRows = 0;
    ms->nCols = 0;
}

void inputMatrix(matrix *m){
    for (int i = 0; i < m->nRows; i++){
        printf("input %d row:", i + 1);
        for (int j = 0; j < m->nCols; j++)
            scanf("%d", &m->values[i][j]);
    }
}

void inputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++){
        printf("input %d mitrix\n", i + 1);
        inputMatrix(ms + 1);
        printf("\n");
    }
}

void outputMatrix(matrix m){
    for (int i = 0; i < m.nRows; i++){
        putchar(124);
        printf(" ");
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        putchar(124);
        printf("\n");
    }

    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices){
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(*(ms + i));
}
