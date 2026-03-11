#include <stdio.h>
#include <stdlib.h>

void printLine(char c, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", c);
    }
    printf("\n");
}

int main()
{

    FILE *file;
    char filename[] = "example.txt";
    char buffer[255];

    // Open file for reading
    file = fopen(filename, "r");

    // Check  if file opened successfully
    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read and display file contents line by line
    printf("Contents of %s\n", filename);
    printLine('-', 23);

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    return 0;
}
