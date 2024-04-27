#include "string/tasks/remove_non_letters.h"
#include "string/tasks/remove_adjacent_equal_letters.h"
#include "string/tasks/reverse_str.h"
#include "string/tasks/replace_digit_to_space.h"
#include "string/tasks/replace_word_to_word.h"
#include "string/tasks/lexicographical_str.h"
#include "string/tasks/print_reverse_str.h"
#include "string/tasks/counter_palindrome_words.h"
#include "string/tasks/alternation_words_from_strs.h"

int main() {
    test_remove_non_letters();
    test_2_remove_adjacent_equal_letters();
    test_3_reverse_str();
    test_4_replace_digit_to_space();
    test_5_replace_word_to_word();
    test_6_lexicographical_str();
    test_7_print_reverse_ordered();
    test_8_counter_palindrome_word();
    test_9_alternation_words();
    return 0;
}

