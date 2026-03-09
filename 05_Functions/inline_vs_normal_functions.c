#include <stdio.h>

// Normal function
int normalAdd(int a, int b)
{
    return a + b;
}

// Inline function
inline int inlineAdd(int a, int b)
{
    return a + b;
}

int main()
{

    int x = 5, y = 10;

    int result1 = normalAdd(x, y);
    int result2 = inlineAdd(x, y);

    printf("Normal Function Result: %d\n", result1);
    printf("Inline Function Result: %d\n", result2);

    return 0;
}