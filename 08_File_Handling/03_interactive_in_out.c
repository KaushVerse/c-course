#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100
#define MAX_LINES 10

int main()
{
    FILE *file;
    char filename[] = "notes.txt";
    char input[MAX_LINE];
    char lines[MAX_LINES][MAX_LINE];
    int count = 0;

    // === WRITE user input using fputs() ===
    printf("Enter up to %d lines of text (type 'quit' to stop):\n", MAX_LINES);

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error creating file\n");
        return 1;
    }

    while (count < MAX_LINES)
    {
        printf("Line %d: ", count + 1);
        fgets(input, sizeof(input), stdin);

        // Check for quit command
        input[strcspn(input, "\n")] = 0; // Remove newline
        if (strcmp(input, "quit") == 0)
        {
            break;
        }

        // Write to file (add newline back)
        fputs(input, file);
        fputs("\n", file);

        // Also save in array for later display
        strcpy(lines[count], input);
        count++;
    }

    fclose(file);
    printf("\n%d lines written to %s\n\n", count, filename);

    // === READ back using fgets() ===
    printf("Reading back from file:\n");
    printf("----------------------\n");

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading\n");
        return 1;
    }

    int line_num = 1;
    while (fgets(input, sizeof(input), file) != NULL)
    {
        // Remove newline for display
        input[strcspn(input, "\n")] = 0;
        printf("Line %d: %s\n", line_num++, input);
    }

    fclose(file);

    return 0;
}