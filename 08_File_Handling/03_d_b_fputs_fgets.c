#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char filename[] = "comparison.txt";
    char buffer[100];
    char str1[50], str2[50];
    int num;

    // === fputs vs fprintf ===
    file = fopen(filename, "w");

    // fputs - simple string output (no formatting)
    fputs("Simple string\n", file);

    // fprintf - formatted output
    fprintf(file, "Formatted: %s %d\n", "Hello", 42);

    fclose(file);

    // === fgets vs fscanf ===
    file = fopen(filename, "r");

    // fgets - reads entire line including spaces
    fgets(buffer, sizeof(buffer), file);
    printf("fgets read: %s", buffer);

    // fscanf - reads formatted data, stops at whitespace
    fscanf(file, "%s %s %d", str1, str2, &num);
    printf("fscanf read: %s %s %d\n", str1, str2, num);

    fclose(file);

    return 0;
}