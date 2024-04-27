#ifndef UNTITLED1_CHANGE_WORD_ORDER_H
#define UNTITLED1_CHANGE_WORD_ORDER_H

#include "../../string/string_.h"

void change_word_order(char *s) {
    if (strlen_(s) == 0)
        return;

    char* rec_ptr = s;
    char* r_buffer_begin = copy(s, s + strlen_(s), _string_buffer) - 1;
    char* r_buffer_end = _string_buffer;

    word_descriptor word;

    while (get_word_reverse(r_buffer_begin, r_buffer_end, &word)) {
        rec_ptr = copy(word.begin, word.end + 1, rec_ptr);

        if (word.begin != r_buffer_end) {
            *rec_ptr++ = ' ';
        }

        r_buffer_begin = word.begin - 2;
    }

    *rec_ptr = '\0';
    free_string(_string_buffer);
}

void test_10_empty() {
    char s[] = "";
    change_word_order(s);
    ASSERT_STRING("", s);
}

void test_10_one_word() {
    char s[] = "world";
    change_word_order(s);
    ASSERT_STRING("world", s);
}

void test_10_only_letters() {
    char s[] = "a b c d";
    change_word_order(s);
    ASSERT_STRING("d c b a", s);
}

void test_10_different_word() {
    char s[] = "hello world test";
    change_word_order(s);
    ASSERT_STRING("test world hello", s);
}

void test_10_change_word_order() {
    test_10_empty();
    test_10_one_word();
    test_10_only_letters();
    test_10_different_word();
}

#endif //UNTITLED1_CHANGE_WORD_ORDER_H
