#include <stdio.h>

int main() {
    int a = 10;

    // Pointer declaration
    int *ptr;

    // Pointer ko variable ka address dena
    ptr = &a;

    printf("Value of a: %d\n", a); // 10
    printf("Address of a: %p\n", &a); // 0x0061FF18

    printf("Pointer ptr value (address of a): %p\n", ptr); // 0x0061FF18
    printf("Value at ptr (*ptr): %d\n", *ptr); // 10

    // Pointer se value change karna
    *ptr = 20;

    printf("\nAfter changing value using pointer:\n");
    printf("Value of a: %d\n", a); // 20
    printf("Value at ptr (*ptr): %d\n", *ptr); // 20

    return 0;
}