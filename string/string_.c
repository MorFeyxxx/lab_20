#include "string_.h"

size_t strlen_(const char* begin){
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char* find(char *begin, char *end, int ch){
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char* find_non_space(char *begin){
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char* find_space(char *begin){
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

char* find_non_space_reverse(char* r_begin, const char* r_end) {
    while (r_begin != r_end && isspace(*r_begin))
        r_begin--;

    return r_begin;
}

char* find_space_reverse(char *r_begin, const char *r_end){
    while (r_begin != r_end && !isspace(*r_begin))
        r_begin--;

    return r_begin;
}

int strcmp_(const char *lhs, const char *rhs){
    while (*lhs != '\0' && *rhs != '\0' && *lhs == *rhs){
        lhs++;
        rhs++;
    }

    return *(const unsigned char*) lhs - *(const unsigned char*) rhs;
}

char* copy(const char *begin_source, const char *end_source, char *begin_destination){
    memcpy(begin_destination, begin_source, end_source - begin_source);
    return begin_destination + (end_source - begin_source);
}