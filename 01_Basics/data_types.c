#include <stdio.h>

int main()
{

    // Primary Data Types in C
    int integerVar = 10;      // Integer type
    float floatVar = 5.5f;    // Floating-point type
    double doubleVar = 10.99; // Double precision floating-point type
    char charVar = 'A';       // Character type
    _Bool boolVar = 1;        // Boolean type (C99 and later)

    // Print the values and sizes of each data type
    printf("Integer: %d, Size: %zu bytes\n", integerVar, sizeof(integerVar));
    printf("Float: %.2f, Size: %zu bytes\n", floatVar, sizeof(floatVar));
    printf("Double: %.2f, Size: %zu bytes\n", doubleVar, sizeof(doubleVar));
    printf("Character: %c, Size: %zu bytes\n", charVar, sizeof(charVar));
    printf("Boolean: %d, Size: %zu bytes\n", boolVar, sizeof(boolVar));

    // Derived Data Types
    int arr[5] = {1, 2, 3, 4, 5}; // Array type

    int *ptr = arr; // Pointer type

    struct Point
    { // Structure type
        int x;
        int y;
    } point = {10, 20};

    enum Color
    {
        RED,
        GREEN,
        BLUE
    }; // Enumeration type
    enum Color color = GREEN;

    union Data
    { // Union type
        int i;
        float f;
        char str[20];
    } data;
    data.i = 10;

    // Print derived data types
    printf("Array first element: %d, Size: %zu bytes\n", arr[0], sizeof(arr));
    printf("Pointer address: %p, Size: %zu bytes\n", (void *)ptr, sizeof(ptr));
    printf("Structure Point: (%d, %d), Size: %zu bytes\n", point.x, point.y, sizeof(point));
    printf("Enumeration Color: %d, Size: %zu bytes\n", color, sizeof(color));
    printf("Union Data (int): %d, Size: %zu bytes\n", data.i, sizeof(data));

    return 0;
}