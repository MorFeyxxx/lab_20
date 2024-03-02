#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector a = {(int []){1, 2, 3}, 3, 4};
    int *p_index = atVector(&a, 1);
    int *p_last = back(&a);
    int *p_zero = front(&a);

    printf("%d\n", p_index);
    printf("%d\n", p_last);
    printf("%d\n", p_zero);
    return 0;
}

