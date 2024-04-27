#ifndef UNTITLED1_STRING__H
#define UNTITLED1_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define ASSERT_STRING(expected, got) assert_string(expected, got, __FILE__, __FUNCTION__, __LINE__)

typedef struct word_descriptor {
    char* begin;
    char* end;
} word_descriptor;

#define MAX_WORD_SIZE 20
#define MAX_N_WORDS_IN_STRING 100
#define MAX_STRING_SIZE 100

extern char _string_buffer[MAX_STRING_SIZE + 1];

typedef struct bag_of_words {
    word_descriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} bag_of_words;

extern bag_of_words _bag;
extern bag_of_words _bag2;

// возвращает количество символов в строке
size_t strlen_(const char* begin);

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end, не включая end
char* find(char *begin, char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа
char* find_non_space(char *begin);

// возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ.
char* find_space(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с r_begin и заканчивая r_end.
// Если символ не найден, возвращается адрес r_end
char* find_non_space_reverse(char *r_begin, const char *r_end);

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с r_begin и
// заканчивая r_end. Если символ не найден, возвращается адрес r_end.
char* find_space_reverse(char *r_begin, const char *r_end);

// проверяет строки на равенство. Возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs равны,
// иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу begin_destination фрагмент памяти, начиная с адреса begin_source до end_source.
// Возвращает указатель на следующий свободный фрагмент памяти в destination
char* copy(const char *begin_source, const char *end_source, char *begin_destination);

// записывает по адресу begin_destination элементы из фрагмента памяти начиная с begin_source
// заканчивая end_source, удовлетворяющие функции-предикату f. Функция возвращает указатель на
// следующий свободный для записи фрагмент в памяти.
char* copy_if(char *begin_source, const char *end_source, char *begin_destination, int (*f)(int));

// записывает по адресу begin_destination элементы из фрагмента памяти начиная с r_begin_source
// заканчивая r_end_source, удовлетворяющие функции-предикату f. Функция возвращает значение
// begin_destination по окончанию работы функции.
char* copy_if_reverse(char *r_begin_source, const char *r_end_source, char *begin_destination, int (*f)(int));

// Возвращает конец строки
char* get_end_of_string(char* s);

// Функция тестирования строк
void assert_string(const char* expected, char* got, char const* file_name, char const* func_name, int line);

// возвращает значение 0, если слово не было считано, иначе возвращено значение 1 и в переменную word типа WordDescriptor
// будут записаны позиции начала слова, и первого символа после конца слова.
bool get_word(char* begin_search, word_descriptor* word);

// считывает слова с конца строки
bool get_word_reverse(char* r_begin, char* r_end, word_descriptor* word);

// освобождение строки
void free_string(char* string);

// освобождение сумки слов
void free_bag(bag_of_words* bag);

// возвращает значение 1, если слово является полиндромом, иначе 0
bool is_palindrome_word(word_descriptor* word);

#endif //UNTITLED1_STRING__H
