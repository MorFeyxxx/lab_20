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

#endif //UNTITLED1_STRING__H
