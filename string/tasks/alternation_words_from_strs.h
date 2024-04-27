#ifndef UNTITLED1_ALTERNATION_WORDS_FROM_STRS_H
#define UNTITLED1_ALTERNATION_WORDS_FROM_STRS_H

#include "../../string/string_.h"

void append_word(char* result, word_descriptor* word) {
    char* ptr = result;

    while (*ptr != '\0') {
        ptr++;
    }

    char* start = word->begin;

    while (*start != *word->end) {
        *ptr = *start;
        ptr++;
        start++;
    }

    *ptr = ' ';
    ptr++;
    *ptr = '\0';
}

void merge_words(char* s1, char* s2, char* result) {
    word_descriptor word1, word2;

    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;

    while ((isW1Found = get_word(beginSearch1, &word1)),
            (isW2Found = get_word(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            append_word(result, &word1);
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            append_word(result, &word2);
            beginSearch2 = word2.end;
        }
    }
}

void test_9_empty() {
    char result[100] = "";

    char s1[] = "";
    char s2[] = "";

    merge_words(s1, s2, result);
    ASSERT_STRING("", result);
}

void test_9_one_string_empty() {
    char result[100] = "";

    char s1[] = "";
    char s2[] = "test";

    merge_words(s1, s2, result);
    ASSERT_STRING("test ", result);
}

void test_9_different_string() {
    char result[100] = "";

    char s1[] = "I";
    char s2[] = "LIKE";

    merge_words(s1, s2, result);
    ASSERT_STRING("I LIKE ", result);
}

void test_9_different_amount_word_1() {
    char result[100] = "";

    char s1[] = "test";
    char s2[] = "word letter ";

    merge_words(s1, s2, result);
    ASSERT_STRING("test word letter ", result);
}

void test_9_different_amount_word_2() {
    char result[100] = "";

    char s1[] = "word letter";
    char s2[] = "test";

    merge_words(s1, s2, result);
    ASSERT_STRING("word test letter ", result);
}

void test_9_alternation_words() {
    test_9_empty();
    test_9_one_string_empty();
    test_9_different_string();
    test_9_different_amount_word_1();
    test_9_different_amount_word_2();
}


#endif //UNTITLED1_ALTERNATION_WORDS_FROM_STRS_H
