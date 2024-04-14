#ifndef UNTITLED1_FUNCTIONS_FOR_COPYING_H
#define UNTITLED1_FUNCTIONS_FOR_COPYING_H

#include "../../string/string_.h"
#include <memory.h>

void test_copy_1() {
    char s[] = "12345";
    char s_copy[10] = "";

    char *p = copy(s, &s[3], s_copy);

    assert(strcmp_(s_copy, "123") == 0);
    assert(p == &s_copy[3]);
}

void test_copy_2() {
    char s[] = "";
    char s_copy[10] = "";

    char *p = copy(s, s, s_copy);

    assert(strcmp_(s_copy, "") == 0);
    assert(p == &s_copy[0]);
}

void test_copy() {
    test_copy_1();
    test_copy_2();
}

#endif //UNTITLED1_FUNCTIONS_FOR_COPYING_H
