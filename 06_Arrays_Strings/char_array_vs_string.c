#include <stdio.h>

int main()
{

    // Character Array
    char charArray[] = {'H', 'e', 'l', 'l', 'o'};

    // String (null-terminated)
    char str[] = "Hello";

    printf("Character Array Elements:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%c ", charArray[i]);
    }

    printf("\n\nString using %%s: %s\n", str);

    printf("\nString Elements:\n");
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c ", str[i]);
    }

    return 0;
}