#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void process_line(char *line)
{
    // Remove trailing newline
    line[strcspn(line, "\n")] = 0;

    // Convert to uppercase
    for (int i = 0; line[i]; i++)
    {
        line[i] = toupper(line[i]);
    }
}

int main()
{
    FILE *input, *output;
    char filename[] = "text.txt";
    char processed_filename[] = "processed.txt";
    char buffer[512];

    // Create sample input file
    input = fopen(filename, "w");
    if (input == NULL)
    {
        printf("Error creating input file\n");
        return 1;
    }

    fputs("Hello World\n", input);
    fputs("This is a test\n", input);
    fputs("C programming is fun\n", input);
    fputs("File handling with fgets and fputs\n", input);

    fclose(input);

    // Process the file
    input = fopen(filename, "r");
    output = fopen(processed_filename, "w");

    if (input == NULL || output == NULL)
    {
        printf("Error opening files\n");
        return 1;
    }

    printf("Processing file...\n");

    while (fgets(buffer, sizeof(buffer), input) != NULL)
    {
        printf("Original: %s", buffer);
        process_line(buffer);
        printf("Processed: %s\n", buffer);
        fputs(buffer, output);
        fputs("\n", output); // Add newline back
    }

    fclose(input);
    fclose(output);

    printf("\nProcessed file saved as '%s'\n", processed_filename);

    return 0;
}