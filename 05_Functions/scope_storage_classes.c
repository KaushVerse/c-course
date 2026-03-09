#include <stdio.h>

// Global variable (extern by default)
int globalVar = 100;

// Function to demonstrate static variable
void counter()
{
    static int count = 0; // static variable
    count++;
    printf("Static count: %d\n", count); // 1, 2, 3
}

int main()
{

    // auto variable (default for local variables)
    auto int a = 10;

    // register variable
    register int b = 20;

    printf("Auto variable a: %d\n", a); // 10
    printf("Register variable b: %d\n", b); // 20

    printf("Global variable: %d\n", globalVar); // 100

    // calling function multiple times
    counter();
    counter();
    counter();

    return 0;
}