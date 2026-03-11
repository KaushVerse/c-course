#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    FILE *file;
    char filename[] = "data.txt";
    char *data[] = {"First line", "Second line", "Third line"};
    int num_lines = sizeof(data) / sizeof(data[0]);

    // Try to open file for writing
    file = fopen(filename, "w");

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file '%s': %s\n",
                filename, strerror(errno));
        return 1;
    }

    // Write data with error checking
    for (int i = 0; i < num_lines; i++)
    {
        if (fprintf(file, "Line %d: %s\n", i + 1, data[i]) < 0)
        {
            fprintf(stderr, "Error writing to file at line %d\n", i + 1);
            fclose(file);
            return 1;
        }
    }

    // Check for write errors
    if (ferror(file))
    {
        fprintf(stderr, "Error occurred while writing to file\n");
        fclose(file);
        return 1;
    }

    printf("Successfully wrote %d lines to %s\n", num_lines, filename);

    fclose(file);
    return 0;
}