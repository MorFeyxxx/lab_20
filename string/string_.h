#ifndef UNTITLED1_STRING__H
#define UNTITLED1_STRING__H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

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
// расположенный на ленте памяти, начиная с rbegin и заканчивая rend.
// Если символ не найден, возвращается адрес rend
char* find_non_space_reverse(char *rbegin, const char *rend);
#endif //UNTITLED1_STRING__H
