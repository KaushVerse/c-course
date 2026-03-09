#include <stdio.h>

int main()
{

    double num1, num2;
    char operator;

    printf("🧮 SIMPLE CALCULATOR\n");

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator)
    {
    case '+':
        printf("Result = %2.lf\n", num1 + num2);
        break;

    case '-':
        printf("Result = %2.lf\n", num1 - num2);
        break;

    case '*':
        printf("Result = %2.lf\n", num1 * num2);
        break;

    case '/':
        if (num2 != 0)
            printf("Result = %2.lf\n", num1 / num2);
        else
            printf("❌ Division by zero not allowed\n");
        break;

    default:
        printf("❌ Invalid operator\n");
    }

    return 0;
}