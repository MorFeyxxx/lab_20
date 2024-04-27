#ifndef UNTITLED1_COUNTER_PALINDROME_WORDS_H
#define UNTITLED1_COUNTER_PALINDROME_WORDS_H

#include "../../string/string_.h"

int get_separate_word(char* begin_search, word_descriptor* word) {
    word->begin = find_non_space(begin_search);

    if (*word->begin == '\0')
        return false;

    word->end = find_space(word->begin);

    if (ispunct(*(word->end - 1)))
        word->end--;

    return true;
}

int counter_palindrome_words(char* s) {
    int amount_palindrome = 0;
    char* begin_search = s;

    word_descriptor word;

    while (get_separate_word(begin_search, &word)) {
        if (is_palindrome_word(&word))
            amount_palindrome++;
        if (ispunct(*(word.end)))
            word.end++;

        begin_search = word.end;
    }

    return amount_palindrome;
}

void test_8_non_palindrome() {
    char s[] = "biba, boba, troba";
    assert(counter_palindrome_words(s) == 0);
}

void test_8_only_letters() {
    char s[] = "a b c d";
    assert(counter_palindrome_words(s) == 4);
}

void test_8_only_palindrome() {
    char s[] = "ara, non, boob";
    assert(counter_palindrome_words(s) == 3);
}

void test_8_different_string() {
    char s[] = "boob, bread, non, civic, apple";
    assert(counter_palindrome_words(s) == 3);
}

void test_8_counter_palindrome_word() {
    test_8_non_palindrome();
    test_8_only_letters();
    test_8_only_palindrome();
    test_8_different_string();
}

#endif //UNTITLED1_COUNTER_PALINDROME_WORDS_H
