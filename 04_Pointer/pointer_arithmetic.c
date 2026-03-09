#include <stdio.h>

    int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int *ptr = arr; // pointer first element ko point karega

    printf("Base Address: %p\n", ptr); // 0x0061FF08
    printf("Value at ptr: %d\n\n", *ptr); // 10

    // Pointer arithmetic
    ptr++; // next element par move

    printf("After ptr++\n");
    printf("Address: %p\n", ptr); // 0x0061FF0C
    printf("Value: %d\n\n", *ptr); // 20

    ptr = ptr + 2; // 2 elements aage move

    printf("After ptr + 2\n");
    printf("Address: %p\n", ptr); // 0x0061FF14
    printf("Value: %d\n\n", *ptr); // 40

    ptr--; // ek element peeche

    printf("After ptr--\n"); 
    printf("Address: %p\n", ptr); // 0x0061FF10
    printf("Value: %d\n", *ptr); // 30

    return 0;
}
