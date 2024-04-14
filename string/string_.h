#ifndef UNTITLED1_STRING__H
#define UNTITLED1_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>

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

#endif //UNTITLED1_STRING__H
