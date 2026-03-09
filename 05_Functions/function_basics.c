#include <stdio.h>

// Function declaration
void greet();

// Function definition
void greet()
{
    printf("Hello, welcome to C functions!\n");
}

int main()
{

    printf("Program started\n");

    // Function call
    greet();

    printf("Program finished\n");

    return 0;
}