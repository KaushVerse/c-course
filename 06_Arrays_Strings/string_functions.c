#include <stdio.h>
#include <string.h>

int main()
{

    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];

    // strlen() - length of string
    printf("Length of str1: %lu\n", strlen(str1)); // 5

    // strcpy() - copy string
    strcpy(str3, str1);
    printf("Copied string (str3): %s\n", str3); // Hello

    // strcat() - concatenate strings
    strcat(str1, " ");
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1); // Hello World

    // strcmp() - compare strings
    int result = strcmp(str1, str2);

    if (result == 0)
        printf("Strings are equal\n");
    else if (result < 0)
        printf("str1 is smaller than str2\n"); // Correct
    else
        printf("str1 is greater than str2\n");

    // strchr() - find character in string
    char *pos = strchr(str1, 'W');

    if (pos != NULL)
        printf("Character 'W' found at position: %ld\n", pos - str1); // Character 'W' found at position: 6
    else
        printf("Character not found\n");

    return 0;
}