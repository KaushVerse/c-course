#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char filename[] = "strings.txt";
    char buffer[256];

    // === WRITING with fputs() ===
    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error creating file\n");
        return 1;
    }

    // Write strings to file (fputs doesn't add newline automatically)
    fputs("Hello, World!", file);
    fputs("\n", file);                       // Manually add newline
    fputs("This is a test string.\n", file); // Newline included
    fputs("Third line with more text.\n", file);

    printf("Data written to %s using fputs()\n", filename);
    fclose(file);

    // === READING with fgets() ===
    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    printf("\nReading file with fgets():\n");
    printf("--------------------------\n");

    // Read and display each line
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // fgets includes newline in buffer, remove it for clean output
        buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
        printf("Line: %s\n", buffer);
    }

    fclose(file);

    return 0;
}