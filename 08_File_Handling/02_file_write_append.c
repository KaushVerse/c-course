#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char filename[] = "output.txt";

    // Open file for writing (creates new file or overwrites existing)
    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error: Could not create file %s\n", filename);
        return 1;
    }

    // Write to file
    fprintf(file, "Hello, World!\n");
    fprintf(file, "This is line 2\n");
    fprintf(file, "Number %d\n", 42);

    printf("Successfully wrote to %s\n", filename);

    fclose(file);

    return 0;
}