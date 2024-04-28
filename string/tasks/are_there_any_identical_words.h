#ifndef UNTITLED1_ARE_THERE_ANY_IDENTICAL_WORDS_H
#define UNTITLED1_ARE_THERE_ANY_IDENTICAL_WORDS_H

#include "../../string/string_.h"

bool are_equal_words_in_string(char* s) {
    char* begin_buff = _string_buffer;

    copy(s, s + strlen_(s), _string_buffer);

    while (get_word_without_space(begin_buff, &_bag.words[_bag.size])) {
        begin_buff = _bag.words[_bag.size].end + 2;
        _bag.size++;
    }

    free_string(_string_buffer);

    if (_bag.size <= 1)
        return false;

    for (size_t i = 0; i < _bag.size; i++)
        for (size_t j = i + 1; j < _bag.size; j++)
            if (is_word_equal(_bag.words[i], _bag.words[j])) {
                free_bag(&_bag);
                return true;
            }

    free_bag(&_bag);
    return false;
}

void test_13_empty() {
    char s[] = "";
    assert(!are_equal_words_in_string(s));
}

void test_13_one_word() {
    char s[] = "word";
    assert(!are_equal_words_in_string(s));
}

void test_13_identical_not_in_string() {
    char s[] = "identical words not in string";
    assert(!are_equal_words_in_string(s));
}

void test_13_identical_in_string() {
    char s[] = "string in string";
    assert(are_equal_words_in_string(s));
}

void test_13_are_there_any_identical_words() {
    test_13_empty();
    test_13_one_word();
    test_13_identical_not_in_string();
    test_13_identical_in_string();
}

#endif //UNTITLED1_ARE_THERE_ANY_IDENTICAL_WORDS_H
