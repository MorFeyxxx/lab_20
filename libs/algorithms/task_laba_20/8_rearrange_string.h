#ifndef UNTITLED1_8_REARRANGE_STRING_H
#define UNTITLED1_8_REARRANGE_STRING_H

#include <assert.h>

#include "../../../string/string_.h"

void _rearrange_string(const char* s, char* res, const int a[], const int n) {
    for (int i = 0; i < n; i++)
        res[i] = s[a[i]];
}


void rearrange_string(const char* filename) {
    FILE* file = fopen(filename, "r");

    char s[1024] = "";
    fscanf(file, "%s", s);

    size_t len = strlen_(s);
    int* numbers = (int *) malloc(len * sizeof(int));

    for (int i = 0; i < len; i++)
        fscanf(file, "%d", numbers + i);

    fclose(file);


    char res[1024] = "";
    _rearrange_string(s, res, numbers, len);


    file = fopen(filename, "w");

    fprintf(file, "%s", res);

    fclose(file);

    free(numbers);
}


void test_rearrange_string_1_empty_file() {
    const char filename[] = "F:\\laba_op_20\\task_8\\test_1.txt";

    FILE* file = fopen(filename, "w");
    fclose(file);


    rearrange_string(filename);


    file = fopen(filename, "r");

    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "") == 0);
}


void test_rearrange_string_2_one_element() {
    const char filename[] = "F:\\laba_op_20\\task_8\\test_2.txt";

    FILE* file = fopen(filename, "w");

    fprintf(file, "s\n");
    fprintf(file, "0");

    fclose(file);


    rearrange_string(filename);


    file = fopen(filename, "r");

    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "s") == 0);
}


void test_rearrange_string_3_more_element() {
    const char filename[] = "F:\\laba_op_20\\task_8\\test_3.txt";

    FILE* file = fopen(filename, "w");

    fprintf(file, "abap\n");
    fprintf(file, "0 3 2 1");

    fclose(file);


    rearrange_string(filename);


    file = fopen(filename, "r");

    char res[100] = "";
    fscanf(file, "%s", res);

    fclose(file);

    assert(strcmp_(res, "apab") == 0);
}


void test_8_rearrange_string() {
    test_rearrange_string_1_empty_file();
    test_rearrange_string_2_one_element();
    test_rearrange_string_3_more_element();
}

#endif //UNTITLED1_8_REARRANGE_STRING_H
