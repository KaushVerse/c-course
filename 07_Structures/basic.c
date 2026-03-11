/**
 * basics.c
 * A demonstration of basic C program structure
 * Author: Kaushik
 * Date: 2026
 */
#include <stdio.h>
#include <stdlib.h> // For standard library functions

// Constants and Macros
#define MAX_STUDENTS 50
#define PI 3.14159

// Function Prototypes (Declaration)
void printWelcome(void);
int calculateSum(int a, int b);
float calculateArea(float radius);

// Global Variables (use sparingly)
int globalCounter = 0;

int main()
{

    // Local variable declarations
    int num1 = 10, num2 = 20, result;
    float radius = 5.0;

    printWelcome();

    // Demonstrate function calls
    result = calculateSum(num1, num2);
    printf("Sum of %d and %d is: %d\n", num1, num2, result);

    float area = calculateArea(radius);
    printf("Area of circle with radius %.2f is %.2f\n", radius, area);

    // Demonstrate global variable
    globalCounter++;
    printf("Global counter: %d\n", globalCounter);

    return 0;
}

/**
 * Prints a welcome message
 */

void printWelcome(void)
{
    printf("=== Program Structure Demo ===\n");
    printf("Welcome to C Programming!\n\n");
}

/**
 * Calculate the sum of two integers
 * @param a First integer
 * @param b Second integer
 * @return Sum of a and b
 */

int calculateSum(int a, int b)
{
    int sum = a + b;
    return sum;
}

/**
 * Calculates the area of a circle
 * @param radius Radius of the circle
 * @return Area of the circle
 */

float calculateArea(float radius)
{
    return PI * radius * radius;
}