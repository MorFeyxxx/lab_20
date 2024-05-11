#ifndef UNTITLED1_EVALUATE_EXPRESSION_H
#define UNTITLED1_EVALUATE_EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "../../string/string_.h"

void evaluate_expression(const char* filename) {
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    int x1, x2, x3;
    char op1, op2;
    char open_bracket, close_bracket;
    float result;

    int amount_element = fscanf(file, "%c%d %c %d%c %c %d", &open_bracket, &x1, &op1, &x2, &close_bracket, &op2, &x3);

    bool two_operation = amount_element == 7 ? true : false;

    switch (op1) {
        case '+':
            result = x1 + x2;
            break;
        case '-':
            result = x1 -x2;
            break;
        case '*':
            result = x1 * x2;
            break;
        case '/':
            if (x2 == 0) {
                fprintf(stderr, "Zero division");
                exit(1);
            }

            result = x1 / x2;
            break;
        default:
            fprintf(stderr,"unknown operation");
            exit(1);
    }

    if (two_operation) {
        switch (op2) {
            case '+':
                result += x3;
                break;
            case '-':
                result -= x3;
                break;
            case '*':
                result *= x3;
                break;
            case '/':
                if (x3 == 0) {
                    fprintf(stderr, "Zero division");
                    exit(1);
                }
                result /= x3;
                break;
            default:
                fprintf(stderr,"unknown operation");
                exit(1);
        }
    }

    fseek(file, 0, SEEK_END);
    fprintf(file, " = %.2f", result);

    fclose(file);
}


void test_evaluate_expression_1_empty_file() {
    /* если файл пуст, то будет выведено сообщение unknown operation */
}


void test_evaluate_expression_2_two_operand() {
    const char filename[] = "F:\\laba_op_19\\task_3\\test_2.txt";

    char expression[] = "(2 + 2)";
    FILE* file = fopen(filename, "w");

    fputs(expression, file);

    fclose(file);


    evaluate_expression(filename);


    file = fopen(filename, "r");

    char data[100] = "";
    fgets(data, sizeof(data), file);

    fclose(file);

    char check[] = "(2 + 2) = 4.00 ";

    assert(strcmp_(data, check));
}


void test_evaluate_expression_3_three_operand() {
    const char filename[] = "F:\\laba_op_19\\task_3\\test_3.txt";

    char expression[] = "(2 * 2) + 2";
    FILE* file = fopen(filename, "w");

    fputs(expression, file);

    fclose(file);


    evaluate_expression(filename);


    file = fopen(filename, "r");

    char data[100] = "";
    fgets(data, sizeof(data), file);

    fclose(file);

    char check[] = "(2 * 2) + 2 = 6.00 ";

    assert(strcmp_(data, check));
}


void test_evaluate() {
    test_evaluate_expression_1_empty_file();
    test_evaluate_expression_2_two_operand();
    test_evaluate_expression_3_three_operand();
}


#endif //UNTITLED1_EVALUATE_EXPRESSION_H
