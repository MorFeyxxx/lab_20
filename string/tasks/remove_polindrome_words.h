#ifndef UNTITLED1_REMOVE_POLINDROME_WORDS_H
#define UNTITLED1_REMOVE_POLINDROME_WORDS_H

#include "../../string/string_.h"

void remove_palindrome_word(char* s) {
    char* read_begin = _string_buffer;
    char* read_end = copy(s, s + strlen_(s), _string_buffer);
    char* rec_ptr = s;

    word_descriptor word;

    while (get_word(read_begin, &word)) {
        if (!is_palindrome_word(&word)) {
            rec_ptr = copy(word.begin, word.end, rec_ptr);
            if (read_end != word.end)
                *rec_ptr++ = ' ';
        }

        read_begin = word.end + 1;
    }

    *rec_ptr = '\0';
    free_string(_string_buffer);
}

void test_17_empty() {
    char s[] = "";
    remove_palindrome_word(s);
    ASSERT_STRING("", s);
}

void test_17_no_palindrome() {
    char s[] = "no palindrome";
    remove_palindrome_word(s);
    ASSERT_STRING("no palindrome", s);
}

void test_17_only_letters() {
    char s[] = "a b c d";
    remove_palindrome_word(s);
    ASSERT_STRING("", s);
}

void test_17_different_string() {
    char s[] = "ara luck world a b bim word mem";
    remove_palindrome_word(s);
    ASSERT_STRING("luck world bim word ", s);
}

void test_17_remove_palindrome_words() {
    test_17_empty();
    test_17_no_palindrome();
    test_17_only_letters();
    test_17_different_string();
}

#endif //UNTITLED1_REMOVE_POLINDROME_WORDS_H
