#include <stdio.h>

int main()
{

    // Array declaration
    int arr[5] = {10, 20, 30, 40, 50};

    // Accessing array elements
    printf("First element: %d\n", arr[0]);  // 10
    printf("Second element: %d\n", arr[1]); // 20

    // Modifying array element
    arr[2] = 35;

    printf("Modified third element: %d\n", arr[2]); // 35

    // Printing all elements using loop
    printf("\nAll array elements:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]); // arr[0] = 10, arr[1] = 20, arr[2] = 35, arr[3] = 40, arr[4] = 50
    }

    return 0;
}
