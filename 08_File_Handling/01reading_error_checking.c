#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char filename[] = "example.txt";
    char buffer[100];

    file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read specific number of characters
    size_t bytes_read = fread(buffer, sizeof(char), 99, file);
    buffer[bytes_read] = '\0'; // Null terminate

    printf("Read %zu bytes: %s\n", bytes_read, buffer);

    // Check for errors
    if (ferror(file))
    {
        printf("Error reading file\n");
    }

    fclose(file);
    return 0;
}