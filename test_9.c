#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: $s <source file> <target file> <N>\n", argv[0]);
        return 1;
    }

    FILE *source_file, *target_file;
    int N, number;

    source_file = fopen(argv[1], "r");
    if (source_file == NULL) {
        printf("Failed to open source file\n");
        return 1;
    }

    target_file = fopen(argv[2], "w");
    if (target_file == NULL) {
        printf("Failed to open target file\n");
        return 1;
    }

    N = atoi(argv[3]);

    while (fscanf(source_file, "%d", &number) != EOF) {
        if (number < N)
            fprintf(target_file, "%d ", number);
    }

    fclose(source_file);
    fclose(target_file);

    return 0;
}
