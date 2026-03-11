#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    // Open source file for reading
    source = fopen(argv[1], "r");
    if (source == NULL)
    {
        printf("Error: Cannot open source file '%s'\n", argv[1]);
        return 1;
    }

    // Open destination file for writing
    destination = fopen(argv[2], "w");
    if (destination == NULL)
    {
        printf("Error: Cannot create destination file '%s'\n", argv[2]);
        fclose(source);
        return 1;
    }

    // Copy file line by line
    int lines_copied = 0;
    while (fgets(buffer, BUFFER_SIZE, source) != NULL)
    {
        fputs(buffer, destination);
        lines_copied++;
    }

    printf("File copied successfully!\n");
    printf("Lines copied: %d\n", lines_copied);

    fclose(source);
    fclose(destination);

    return 0;
}