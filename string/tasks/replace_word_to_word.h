#ifndef UNTITLED1_REPLACE_WORD_TO_WORD_H
#define UNTITLED1_REPLACE_WORD_TO_WORD_H

#include "../../string/string_.h"

int compare(char* lhs, char* rhs, size_t size) {
    size_t i = 0;
    while (i != size && *lhs == *rhs) {
        i++;
        lhs++;
        rhs++;
    }

    if (i == size)
        return 1;

    return 0;
}
void replace(char* source, char* w1, char* w2) {
    size_t w1_size = strlen_(w1);
    size_t w2_size = strlen_(w2);

    word_descriptor word1 = {w1, w1 + w1_size};
    word_descriptor word2 = {w2, w2 + w2_size};

    char *read_ptr;
    char *rec_ptr;

    if (w1_size >= w2_size) {
        read_ptr = source;
        rec_ptr = source;
    } else {
        copy(source, get_end_of_string(source), _string_buffer);
        read_ptr = _string_buffer;
        rec_ptr = source;
    }

    while (*read_ptr != '\0') {
        if (compare(read_ptr, word1.begin, word1.end - word1.begin)) {
            copy(word2.begin, word2.end, rec_ptr);
            rec_ptr += word2.end - word2.begin;
            read_ptr += word1.end - word1.begin;
        } else {
            *rec_ptr = *read_ptr;
            rec_ptr++;
            read_ptr++;
        }
    }

    *rec_ptr = '\0';
    free_string(_string_buffer);
}

void test_5_empty() {
    char source[] = "";
    char w1[] = "hello";
    char w2[] = "world";
    replace(source, w1, w2);
    ASSERT_STRING("", source);
}

void test_5_word_not_in_string() {
    char source[] = "hello world";
    char w1[] = "Go";
    char w2[] = "dota";
    replace(source, w1, w2);
    ASSERT_STRING("hello world", source);
}

void test_5_word_equal_length() {
    char source[] = "hello world";
    char w1[] = "world";
    char w2[] = "tasks";
    replace(source, w1, w2);
    ASSERT_STRING("hello tasks", source);
}

void test_5_word_different_length() {
    char source[] = "hello world";
    char w1[] = "world";
    char w2[] = "Bim";
    replace(source, w1, w2);
    ASSERT_STRING("hello Bim", source);
}

void test_5_word_different_length_two() {
    char source[] = "hello world";
    char w1[] = "world";
    char w2[] = "hunters";
    replace(source, w1, w2);
    ASSERT_STRING("hello hunters", source);
}

void test_5_replace_word_to_word() {
    test_5_empty();
    test_5_word_not_in_string();
    test_5_word_equal_length();
    test_5_word_different_length();
    test_5_word_different_length_two();
}

#endif //UNTITLED1_REPLACE_WORD_TO_WORD_H
