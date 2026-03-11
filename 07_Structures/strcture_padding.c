#include <stdio.h>

struct Example
{
    char a;
    int b;
    char c;
};

int main()
{
    printf("Size of struct: %lu\n", sizeof(struct Example));
    return 0;
}