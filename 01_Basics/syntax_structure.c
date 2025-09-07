#include <stdio.h>
#define PI 3.14

void greet() // Function Declaration
{
    printf("Hello, welcome to C programming!\n");
}
int main()
{
    int radius;
    float area;

    printf("Enter radius of circle: ");
    scanf("%d", &radius);

    area = PI * radius * radius;
    printf("Area of circle: %.2f\n", area);

    greet(); // Function Call
    return 0;
}