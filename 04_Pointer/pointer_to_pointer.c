#include <stdio.h>

int main()
{
    int a = 50;

    int *ptr;   // pointer to int
    int **pptr; // pointer to pointer

    ptr = &a;    // ptr stores address of a
    pptr = &ptr; // pptr stores address of ptr

    printf("Value of a: %d\n", a); // 50

    printf("Address of a: %p\n", &a);                 // 0x0061FF18
    printf("Value of ptr (address of a): %p\n", ptr); // 0x0061FF18
    printf("Address of ptr: %p\n", &ptr);             // 0x0061FF14

    printf("\nUsing single pointer (*ptr): %d\n", *ptr); // 50

    printf("Using double pointer (**pptr): %d\n", **pptr); // 50

    // Changing value using double pointer
    **pptr = 100;

    printf("\nAfter changing value using double pointer:\n");
    printf("Value of a: %d\n", a); // 100

    return 0;
}