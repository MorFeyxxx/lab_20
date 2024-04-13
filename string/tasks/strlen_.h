#ifndef UNTITLED1_STRLEN__H
#define UNTITLED1_STRLEN__H

#include "../../string/string_.h"

void test_strlen_with_reserved_memory(){
    char s[10] = "Hello";

    size_t len = strlen_(s);
    assert(len == 5);
}

void test_strlen_empty(){
    char s[] = "";

    size_t len = strlen_(s);
    assert(len == 0);
}

void test_strlen_not_empty(){
    char s[] = "\tHello\t";

    size_t len = strlen_(s);
    assert(len == 7);
}

void test_strlen_(){
    test_strlen_with_reserved_memory();
    test_strlen_empty();
    test_strlen_not_empty();
}

#endif //UNTITLED1_STRLEN__H
