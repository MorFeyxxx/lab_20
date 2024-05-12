#ifndef UNTITLED1_GET_BEST_TEAM_H
#define UNTITLED1_GET_BEST_TEAM_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "../../string/string_.h"

#define MAX_LENGTH_STRING 200
#define MAX_AMOUNT_SPORTSMAN 20


typedef struct sportsman {
    char name[MAX_LENGTH_STRING];
    int best_result;
} sportsman;


static void generate_name(char* s) {
    int name_length = rand() % 30 + 5;

    char* rec_ptr = s;
    for (int i = 0; i < name_length; i++) {
        *rec_ptr = rand() % 26 + 97;
        rec_ptr++;
    }
    *rec_ptr = '\0';
}


void swap_sm(sportsman *a, sportsman *b){
    sportsman temp = *a;
    *a = *b;
    *b = temp;
}


void sort_sportsman(sportsman sm[], const int n) {
    for (int i = 0; i < n - 1; i++){
        int max_index = i;
        for (int j = i + 1; j < n; j++)
            if (sm[max_index].best_result < sm[j].best_result) {
                max_index = j;
            }

        swap_sm(&sm[i], &sm[max_index]);
    }

}


void get_best_team(const char* filename, const int n) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    sportsman* team = (sportsman*) malloc(MAX_AMOUNT_SPORTSMAN * sizeof(sportsman));

    sportsman* rec_ptr = team;
    int amount_sportsman = 0;
    while (fread(rec_ptr, sizeof(sportsman), 1, file) == 1) {
        rec_ptr ++;
        amount_sportsman++;
    }

    fclose(file);


    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    sort_sportsman(team, amount_sportsman);

    int amount_in_team = amount_sportsman >= n ? n : amount_sportsman;

    for (int i = 0; i < amount_in_team; i++) {
        fwrite(team + i, sizeof(sportsman), 1, file);
    }

    free(team);
    fclose(file);
}


void print_team(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    sportsman s;
    while (fread(&s, sizeof(sportsman), 1, file) == 1) {
        printf("%s %d", s.name, s.best_result);
        printf("\n");
    }

    fclose(file);
}


void test_get_best_team_1_empty_file() {
    const char filename[] = "F:\\laba_op_19\\task_9\\test_1.txt";

    FILE* file = fopen(filename, "wb");
    fclose(file);

    get_best_team(filename, 0);

    file = fopen(filename, "rb");

    char data[100] = "";
    fread(data, sizeof(data), 1, file);

    fclose(file);

    assert(strcmp_(data, "") == 0);
}


void test_get_best_team_2_n_two_athletes() {
    const char filename[] = "F:\\laba_op_19\\task_9\\test_2.txt";

    FILE* file = fopen(filename, "wb");

    sportsman s1 = {.best_result = 10, .name="first"};
    sportsman s2 = {.best_result = 5,  .name="second"};

    fwrite(&s1, sizeof(sportsman), 1, file);
    fwrite(&s2, sizeof(sportsman), 1, file);

    fclose(file);

    get_best_team(filename, 3);

    file = fopen(filename, "rb");

    sportsman res_s1, res_s2;
    fread(&res_s1, sizeof(sportsman), 1, file);
    fread(&res_s2, sizeof(sportsman), 1, file);

    fclose(file);

    assert(strcmp_(s1.name, res_s1.name) == 0 && s1.best_result == res_s1.best_result);
    assert(strcmp_(s2.name, res_s2.name) == 0 && s2.best_result == res_s2.best_result);
}


void test_get_best_team_3_n_more_athletes() {
    const char filename[] = "F:\\laba_op_19\\task_9\\test_3.txt";

    FILE* file = fopen(filename, "wb");

    sportsman s1 = {.best_result = 10, .name="first"};
    sportsman s2 = {.best_result = 5,  .name="second"};

    fwrite(&s1, sizeof(sportsman), 1, file);
    fwrite(&s2, sizeof(sportsman), 1, file);

    fclose(file);

    get_best_team(filename, 1);

    file = fopen(filename, "rb");

    sportsman res_s1;
    fread(&res_s1, sizeof(sportsman), 1, file);

    fclose(file);

    assert(strcmp_(s1.name, res_s1.name) == 0 && s1.best_result == res_s1.best_result);
}


void test_get_best_team() {
    test_get_best_team_1_empty_file();
    test_get_best_team_2_n_two_athletes();
    test_get_best_team_3_n_more_athletes();
}

#endif //UNTITLED1_GET_BEST_TEAM_H
