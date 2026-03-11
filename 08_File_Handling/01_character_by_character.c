#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char filename[] = "example.txt";
    int ch;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Read character by character until EOF
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
    return 0;
}