#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    char * op = argv[1];
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int result;

    if (argc != 4) {
        printf("Usage: %s [add|sub|multi|div] num1 num2\n", argv[0]);
        return 1;
    }

    printf("----- Hacker Calculater -----\n");

    if (strcmp(op, "add") == 0) {
        result = a + b;
        printf("Adding: %d + %d = %d\n", a, b, result);
    }
    else if (strcmp(op, "sub") == 0) {
        result = a - b;
        printf("Subtrating: %d - %d = %d\n", a, b, result);
    }
    else if (strcmp(op, "multi") == 0) {
        result = a * b;
        printf("Multiplication: %d * %d = %d\n", a, b, result);
    }
    else if (strcmp(op, "div") == 0) {
        if (b == 0) {
            printf("Error: Divisible by zero!\n");
            return 1;
        }
        result = a / b;
        printf("Dividing: %d / %d = %d\n", a, b, result);
    }
    else {
        printf("Invalid Option, program exiting...\n");
        return 1;
    }

    return 0;
}