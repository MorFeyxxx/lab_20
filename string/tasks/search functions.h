#ifndef UNTITLED1_SEARCH_FUNCTIONS_H
#define UNTITLED1_SEARCH_FUNCTIONS_H

#include "../../string/string_.h"

void test_find_the_desired_element_in_the_range(){
    char s[] = "Hello";
    char *find_element = find(s, &s[3], 'l');

    assert(find_element == &s[2]);
}

void test_find_the_desired_element_is_not_in_the_range(){
    char s[] = "Hello";
    char *find_element = find(s, &s[3], 'o');

    assert(find_element == &s[3]);
}

void test_find(){
    test_find_the_desired_element_in_the_range();
    test_find_the_desired_element_is_not_in_the_range();
}

#endif //UNTITLED1_SEARCH_FUNCTIONS_H
