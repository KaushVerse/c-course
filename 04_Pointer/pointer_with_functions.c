#include <stdio.h>

// Function that receives pointer
void modifyValue(int *ptr)
{
    *ptr = *ptr + 10; // original value change
}

int main()
{
    int num = 25;

    printf("Before function call: %d\n", num); // 25

    // Passing address of num
    modifyValue(&num);

    printf("After function call: %d\n", num); // 35

    return 0;
}