/**
 * error_handling.c
 * Demonstrates basic error handling in C
 * Author: Kaushik
 */

#include <stdio.h>
#include <stdlib.h>

/* ==============================
   Utility Function
   ============================== */

void printLine(char c, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}

/* ==============================
   Main Function
   ============================== */

int main()
{
    FILE *fp;
    int *ptr;
    int number;

    printLine('=', 40);
    printf("C ERROR HANDLING DEMO\n");
    printLine('=', 40);

    /* ==============================
       1. File Error Handling
       ============================== */

    fp = fopen("example.txt", "r");

    if (fp == NULL)
    {
        printf("Error: Could not open file!\n");
    }
    else
    {
        printf("File opened successfully.\n");
        fclose(fp);
    }

    /* ==============================
       2. Memory Allocation Error
       ============================== */

    ptr = (int *)malloc(sizeof(int) * 5);

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    else
    {
        printf("Memory allocated successfully.\n");
    }

    free(ptr);

    /* ==============================
       3. Input Error Handling
       ============================== */

    printf("\nEnter a number: ");

    if (scanf("%d", &number) != 1)
    {
        printf("Invalid input! Please enter a number.\n");
        return 1;
    }

    printf("You entered: %d\n", number);

    printLine('=', 40);

    return 0;
}