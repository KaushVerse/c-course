#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    FILE *file;
    char filename[] = "log.txt";
    time_t now;
    char time_str[100];

    // Open file for appending (creates new file if doesn't exist)
    file = fopen(filename, "a");

    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Get current time
    time(&now);
    struct tm *local = localtime(&now);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local);

    // Append to file
    fprintf(file, "[%s] Log entry: Program executed\n", time_str);
    fprintf(file, "[%s] User: %s\n", time_str, getenv("USER"));
    fprintf(file, "------------------------\n");

    printf("Log entry appended to %s\n", filename);

    fclose(file);
    return 0;
}