#ifndef UNTITLED1_FUNCTIONS_FOR_COPYING_H
#define UNTITLED1_FUNCTIONS_FOR_COPYING_H

#include "../../string/string_.h"
#include <memory.h>
#include <stdbool.h>

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


int test(int a){
    if (a == '1' || a == '3' || a == '4' || a == '6')
        return true;

    return false;
}

void test_copy_if_1() {
    char s[] = "1a2b3c4d";
    char s_copy[15] = "";

    char *p = copy_if(s, s + strlen_(s), s_copy, isalpha);

    assert(strcmp_(s_copy, "abcd") == 0);
    assert(p == &s_copy[4]);
}

void test_copy_if_2() {
    char s[] = "123456";
    char s_copy[15] = "";

    char *p = copy_if(s, s + strlen_(s) - 1, s_copy, test);

    assert(strcmp_(s_copy, "134") == 0);
    assert(p == &s_copy[3]);
}

void test_copy_if(){
    test_copy_if_1();
    test_copy_if_2();
}


void test_copy_if_1_reverse() {
    char s[] = "1a2b3c4d";
    char s_copy[15] = "";

    char *p = copy_if_reverse(s + strlen_(s), s, s_copy, isalpha);

    assert(strcmp_(s_copy, "dcba") == 0);
    assert(p == &s_copy[4]);
}

void test_copy_if_2_reverse() {
    char s[] = "123456";
    char s_copy[15] = "";

    char *p = copy_if_reverse(s + strlen_(s) - 1, s, s_copy, test);

    assert(strcmp_(s_copy, "643") == 0);
    assert(p == &s_copy[3]);
}

void test_copy_if_reverse(){
    test_copy_if_1_reverse();
    test_copy_if_2_reverse();
}

#endif //UNTITLED1_FUNCTIONS_FOR_COPYING_H
