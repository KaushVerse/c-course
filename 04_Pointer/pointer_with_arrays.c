#include <stdio.h>

int main()
{
    int arr[5] = {5, 10, 15, 20, 25};

    int *ptr = arr; // arr ka address = &arr[0]

    printf("Array Elements using Pointer\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Value: %d  Address: %p\n", *(ptr + i), (ptr + i)); // 0x0061FEFC, 0x0061FF00, 0x0061FF04, 0x0061FF08, 0x0061FF0C
    }

    printf("\nAccess using array notation:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]); // arr[0] = 5, arr[1] = 10, arr[2] = 15, arr[3] = 20, arr[4] = 25
    }

    printf("\nAccess using pointer notation:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i)); // *(ptr + 0) = 5, *(ptr + 1) = 10, *(ptr + 2) = 15, *(ptr + 3) = 20, *(ptr + 4) = 2
    }

    return 0;
}