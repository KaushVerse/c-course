#include <stdio.h>
#include <string.h>

int main()
{

    // String declaration
    char str[20] = "Hello";

    // Printing string
    printf("String: %s\n", str); // Hello

    // String length
    printf("Length: %lu\n", strlen(str)); // 5

    // String copy
    char str2[20];
    strcpy(str2, str); 
    printf("Copied String: %s\n", str2); // Hello

    // String concatenation
    strcat(str, " World");
    printf("Concatenated String: %s\n", str); // Hello World

    // String comparison
    if (strcmp(str, str2) == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are not equal\n"); // Correct

    return 0;
}