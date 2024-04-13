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


void test_find_non_space_the_desired_element_in_the_range(){
    char s[] = "   a   ";
    char *find_element = find_non_space(s);

    assert(find_element = &s[3]);
}

void test_find_non_space_the_desired_element_is_not_in_the_range(){
    char s[] = "      ";
    char *find_element = find_non_space(s);

    assert(find_element = &s[7]);
}

void test_find_non_space_is_no_space(){
    char s[] = "abc";
    char *find_element = find_non_space(s);

    assert(find_element = &s[0]);
}

void test_find_non_space(){
    test_find_non_space_the_desired_element_in_the_range();
    test_find_non_space_the_desired_element_is_not_in_the_range();
    test_find_non_space_is_no_space();
}

#endif //UNTITLED1_SEARCH_FUNCTIONS_H
