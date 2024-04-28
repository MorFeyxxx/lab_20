#ifndef UNTITLED1_ADDING_STR_H
#define UNTITLED1_ADDING_STR_H

#include "../../string/string_.h"

void complement_string(char* s1, char* s2, size_t n) {
    char* begin_search = s2;

    while (get_word_without_space(begin_search, &_bag.words[_bag.size])) {
        begin_search = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    char* rec_ptr = get_end_of_string(s1);
    *rec_ptr++ = ' ';

    for (size_t i = _bag.size - n; i < _bag.size; i++) {
        rec_ptr = copy(_bag.words[i].begin, _bag.words[i].end + 1, rec_ptr);
        if (i != _bag.size - 1)
            *rec_ptr++ = ' ';
    }

    *rec_ptr = '\0';
    free_bag(&_bag);
}

void balance_string(char* s1, size_t n1, char* s2, size_t n2) {
    if (n1 < n2)
        complement_string(s1, s2, n2 - n1);

    if (n2 < n1)
        complement_string(s2, s1, n1 - n2);
}

void test_18_empty() {
    char s1[40] = "";
    size_t n1 = 0;

    char s2[40] = "";
    size_t n2 = 0;

    balance_string(s1, n1, s2, n2);
    ASSERT_STRING("", s1);
    ASSERT_STRING("", s2);
}

void test_18_fir_empty() {
    char s1[40] = "";
    size_t n1 = 0;

    char s2[40] = "bim bam";
    size_t n2 = 2;

    balance_string(s1, n1, s2, n2);
    ASSERT_STRING(" bim bam", s1);
    ASSERT_STRING("bim bam", s2);
}

void test_18_sec_empty() {
    char s1[40] = "bim bam";
    size_t n1 = 2;

    char s2[40] = "";
    size_t n2 = 0;

    balance_string(s1, n1, s2, n2);
    ASSERT_STRING("bim bam", s1);
    ASSERT_STRING(" bim bam", s2);
}

void test_18_equal_length() {
    char s1[100] = "bim bam";
    size_t n1 = 2;

    char s2[100] = "bam bim";
    size_t n2 = 2;

    balance_string(s1, n1, s2, n2);
    ASSERT_STRING("bim bam", s1);
    ASSERT_STRING("bam bim", s2);
}

void test_18_different_length() {
    char s1[100] = "bim";
    size_t n1 = 1;

    char s2[100] = "bam param ara";
    size_t n2 = 3;

    balance_string(s1, n1, s2, n2);
    ASSERT_STRING("bim param ara", s1);
    ASSERT_STRING("bam param ara", s2);
}

void test_18_complement_string() {
    test_18_empty();
    test_18_fir_empty();
    test_18_sec_empty();
    test_18_equal_length();
    test_18_different_length();
}


#endif //UNTITLED1_ADDING_STR_H
