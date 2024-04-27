#ifndef UNTITLED1_REMOVE_NON_LETTERS_H
#define UNTITLED1_REMOVE_NON_LETTERS_H

#include "../../string/string_.h"

void remove_non_letters(char* s) {
    char* end = get_end_of_string(s);
    char* destination = copy_if(s, end, s, isgraph);

    *destination = '\0';
}

void test_empty() {
    char s[] = " ";
    remove_non_letters(s);
    ASSERT_STRING("", s);
}

void test_non_space() {
    char s[] = "Hi123";
    remove_non_letters(s);
    ASSERT_STRING("Hi123", s);
}

void test_space() {
    char s[] = "Hi 123";
    remove_non_letters(s);
    ASSERT_STRING("Hi123", s);
}

void test_space_in_border() {
    char s[] = "   Hi    12 3    ";
    remove_non_letters(s);
    ASSERT_STRING("Hi123", s);
}

void test_remove_non_letters() {
    test_empty();
    test_non_space();
    test_space();
    test_space_in_border();
}

#endif //UNTITLED1_REMOVE_NON_LETTERS_H
