#ifndef UNTITLED1_FIND_LAST_COMMON_WORD_H
#define UNTITLED1_FIND_LAST_COMMON_WORD_H

#include "../../string/string_.h"

word_descriptor find_last_common_word(char* s1, char* s2) {
    char* begin_search_1 = s1;
    char* begin_search_2 = s2;

    while (get_word_without_space(begin_search_1, &_bag.words[_bag.size])) {
        begin_search_1 = _bag.words[_bag.size].end + 1;
        _bag.size++;
    }

    while (get_word_without_space(begin_search_2, &_bag2.words[_bag2.size])) {
        begin_search_2 = _bag2.words[_bag2.size].end + 1;
        _bag2.size++;
    }

    word_descriptor word = {.begin = NULL, .end = NULL};
    for (int i = (int) _bag.size - 1; i >= 0; i--)
        for (int j = 0; j < _bag2.size; j++)
            if (is_word_equal(_bag.words[i], _bag2.words[j])) {
                word = _bag.words[i];

                free_bag(&_bag);
                free_bag(&_bag2);

                return word;
            }

    return word;
}

void test_12_word_at_end() {
    char s1[] = "I like to play dota";
    char s2[] = "play csgo";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("play", dest);
}

void test_12_no_common_word() {
    char s1[] = "I like to play dota";
    char s2[] = "He does not drink tea";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("", dest);
}

void test_12_word_at_start() {
    char s1[] = "drink tea";
    char s2[] = "drink coffee";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("drink", dest);
}

void test_12_single_word_strings() {
    char s1[] = "drink";
    char s2[] = "drink";

    char dest[MAX_WORD_SIZE] = "";
    word_descriptor word = find_last_common_word(s1, s2);

    word_descriptor_to_string(word, dest);

    ASSERT_STRING("drink", dest);
}

void test_12_find_last_common_word() {
    test_12_word_at_end();
    test_12_word_at_start();
    test_12_no_common_word();
    test_12_single_word_strings();
}

#endif //UNTITLED1_FIND_LAST_COMMON_WORD_H
