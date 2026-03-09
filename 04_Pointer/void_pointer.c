#include <stdio.h>

int main()
{
    int a = 10;
    float b = 5.5;
    char c = 'A';

    void *ptr; // void pointer

    // int ka address
    ptr = &a;
    printf("Integer value: %d\n", *(int *)ptr); // 10

    // float ka address
    ptr = &b;
    printf("Float value: %.2f\n", *(float *)ptr); // 5.50

    // char ka address
    ptr = &c;
    printf("Char value: %c\n", *(char *)ptr); // A

    return 0;
}