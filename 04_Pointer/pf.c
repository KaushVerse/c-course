#include <stdio.h>


void change(int *p)
{
    *p = 50;
}
int main()
{

    int x = 10;
    change(&x);
    printf("Value of x after change: %d\n", x); // Output will be 50
    return 0;
}