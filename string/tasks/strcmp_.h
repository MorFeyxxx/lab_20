#ifndef UNTITLED1_STRCMP__H
#define UNTITLED1_STRCMP__H

#include "../../string/string_.h"

void test_strcmp_is_equal(){
    char s1[] = "123";
    char s2[] = "123";

    assert(strcmp_(&s1, &s2) == 0);
}

void test_strcmp_is_not_equal_1(){
    char s1[] = "123";
    char s2[] = "132";

    assert(strcmp_(&s1, &s2) == -1);
}

void test_strcmp_is_not_equal_2(){
    char s1[] = "132";
    char s2[] = "123";

    assert(strcmp_(&s1, &s2) == 1);
}

void test_strcmp_(){
    test_strcmp_is_equal();
    test_strcmp_is_not_equal_1();
    test_strcmp_is_not_equal_2();
}

#endif //UNTITLED1_STRCMP__H
