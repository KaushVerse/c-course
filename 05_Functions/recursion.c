#include <stdio.h>

// Recursive function
int factorial(int n)
{
    if (n == 0 || n == 1) // base condition
        return 1;
    else
        return n * factorial(n - 1); // recursive call
}

int main()
{
    int num = 5;

    int result = factorial(num);

    printf("Factorial of %d = %d\n", num, result);

    return 0;
}