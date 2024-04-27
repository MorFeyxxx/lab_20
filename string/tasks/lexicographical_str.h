#ifndef UNTITLED1_LEXICOGRAPHICAL_STR_H
#define UNTITLED1_LEXICOGRAPHICAL_STR_H

#include "../../string/string_.h"

int are_words_equal(word_descriptor w1, word_descriptor w2) {
    while (*w1.begin == *w2.begin) {
        w1.begin++;
        w2.begin++;
    }
    return *(const unsigned char*) w1.begin - *(const unsigned char*) w2.begin;
}

bool is_lexicographical_order(char* s) {
    char* begin_search = s;
    word_descriptor word1, word2;

    if (!get_word(begin_search, &word1))
        return true;

    begin_search = word1.end;

    while (get_word(begin_search, &word2)) {
        if (are_words_equal(word1, word2) <= 0)
            word1 = word2;
        else
            return false;

        begin_search = word2.end;
    }

    return true;
}

void test_6_empty() {
    char s[] = "";
    assert(is_lexicographical_order(s));
}

void test_6_one_letters() {
    char s[] = "a";
    assert(is_lexicographical_order(s));
}

void test_6_letters_ordered() {
    char s[] = "a b c";
    assert(is_lexicographical_order(s));
}

void test_6_letters_unordered() {
    char s[] = "a e c";
    assert(!is_lexicographical_order(s));
}

void test_6_word_ordered() {
    char s[] = "abs abs def";
    assert(is_lexicographical_order(s));
}

void test_6_word_unordered() {
    char s[] = "def abs abs";
    assert(!is_lexicographical_order(s));
}

void test_6_lexicographical_str() {
    test_6_empty();
    test_6_one_letters();
    test_6_letters_ordered();
    test_6_letters_unordered();
    test_6_word_ordered();
    test_6_word_unordered();
}

#endif //UNTITLED1_LEXICOGRAPHICAL_STR_H
