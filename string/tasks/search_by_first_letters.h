#ifndef UNTITLED1_SEARCH_BY_FIRST_LETTERS_H
#define UNTITLED1_SEARCH_BY_FIRST_LETTERS_H

#include "../../string/string_.h"

int compare_letters(const void* s1, const void* s2) {
    return *(char *) s1 - *(char *) s2;
}

void sort_word_letters(word_descriptor* word) {
    qsort(word->begin, word->end - word->begin, sizeof(char), compare_letters);
}

bool are_identical_words_in_string(char* s) {
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
        sort_word_letters(&_bag.words[i]);

    for (size_t i = 0; i < _bag.size; i++)
        for (size_t j = i + 1; j < _bag.size; j++)
            if (is_word_equal(_bag.words[i], _bag.words[j])) {
                free_bag(&_bag);
                return true;
            }

    free_bag(&_bag);
    return false;
}

void test_14_empty() {
    char s[] = "";
    assert(!are_identical_words_in_string(s));
}

void test_14_one_word() {
    char s[] = "word";
    assert(!are_identical_words_in_string(s));
}

void test_14_with_the_same_letters_words_not_in_string() {
    char s[] = "identical words not in string";
    assert(!are_identical_words_in_string(s));
}

void test_14_with_the_same_letters_words_in_string() {
    char s[] = "string in string";
    assert(are_identical_words_in_string(s));
}

void test_14_search_by_first_letters() {
    test_14_empty();
    test_14_one_word();
    test_14_with_the_same_letters_words_not_in_string();
    test_14_with_the_same_letters_words_in_string();
}

#endif //UNTITLED1_SEARCH_BY_FIRST_LETTERS_H
