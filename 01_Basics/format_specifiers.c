#include <stdio.h>

int main()
{

    // Integer Types Format Specifiers
    int intVar = 42;
    printf("Integer: %d\n", intVar);                        // %d for int
    printf("Unsigned Integer: %u\n", (unsigned int)intVar); // %u for unsigned int
    printf("Long Integer: %ld\n", (long int)intVar);        // %ld for long int
    printf("Unsigned Long Integer: %lu\n", (unsigned long int)intVar); // %lu for unsigned long int
    printf("Short Integer: %hd\n", (short int)intVar);      // %hd for short int
    printf("Unsigned Short Integer: %hu\n", (unsigned short int)intVar); // %hu for unsigned short int
    printf("Long Long Integer: %lld\n", (long long int)intVar); // %lld for long long int
    printf("Unsigned Long Long Integer: %llu\n", (unsigned long long int)intVar); // %llu for unsigned long long int
    printf("Hexadecimal: %x\n", intVar);                    // %x for hexadecimal
    printf("Octal: %o\n", intVar);                          // %o for oct


    // Floating-Point Types Format Specifiers
    float floatVar = 3.14f;
    double doubleVar = 3.141592653589793;
    long double longDoubleVar = 3.14159265358979323846L;
    printf("Float: %f\n", floatVar);                        // %f for float
    printf("Double: %lf\n", doubleVar);                     // %lf for double
    printf("Long Double: %Lf\n", longDoubleVar);            // %Lf for long double
    printf("Scientific Notation (float): %e\n", floatVar);  // %e for scientific notation (float)
    printf("Scientific Notation (double): %le\n", doubleVar); // %le for scientific notation (double)
    printf("Scientific Notation (long double): %Le\n", longDoubleVar); // %Le for scientific notation (long double)
    printf("Shortest Representation (float): %g\n", floatVar); // %g for shortest representation (float)
    printf("Shortest Representation (double): %lg\n", doubleVar); // %lg for shortest representation (double)
    printf("Shortest Representation (long double): %Lg\n", longDoubleVar); // %Lg for shortest representation (long double)

    // Character and String Types Format Specifiers
    char charVar = 'A';
    char strVar[] = "Hello, World!";
    printf("Character: %c\n", charVar);                     // %c for char
    printf("String: %s\n", strVar);                         // %s for string
    printf("Pointer: %p\n", (void*)strVar);                 // %p for pointer
    printf("Percent Sign: %%\n");                           // %% for percent sign

    
    return 0;
}