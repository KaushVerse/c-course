#include <stdio.h>

int main()
{

    // 🔢 Arithmetic Operators
    int a = 10, b = 3;
    printf("➕ a + b = %d\n", a + b);
    printf("➖ a - b = %d\n", a - b);
    printf("✖️ a * b = %d\n", a * b);
    printf("➗ a / b = %d\n", a / b); // Integer division
    printf("📐 a %% b = %d\n\n", a % b);

    // 🔁 Increment / Decrement Operators
    int x = 5;
    printf("⬆️ x++ = %d\n", x++);
    printf("After x++ : %d\n", x);
    printf("⬇️ --x = %d\n\n", --x);

    // ⚖️ Relational Operators
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n", a != b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n\n", a < b);

    // 🔗 Logical Operators (Drone decision making)
    int battery = 70;
    int gpsLock = 1;
    int emergency = 1;
    int doorLocked = 0;
    int badWeather = 0;

    // && Operator
    if (battery > 50 && gpsLock)
        printf("🛫 Drone Ready to Fly\n");
    else
        printf("⛔ Drone Not Ready\n");

    // || Operator
    if (battery > 30 || emergency == 1)
        printf("🚨 Drone Action Allowed (Fly / Emergency Landing)\n");
    else
        printf("⛔ Drone Action NOT Allowed\n");

    // ! Operator
    if (!doorLocked)
        printf("🚪 Door is OPEN\n");
    else
        printf("🔒 Door is Locked\n");

    // Example
    if ((battery > 50 && gpsLock) && !badWeather)
        printf("🛫 Drone Can Fly Safely\n");
    else
        printf("⛔ Drone Flight Cancelled\n");

    // 🧮 Bitwise Operators (Embedded + Registers)
    int p = 5, q = 3; // p = 0101, q = 0011
    printf("\nAND  (p & q) = %d\n", p & q);
    printf("OR   (p | q) = %d\n", p | q);
    printf("XOR  (p ^ q) = %d\n", p ^ q);
    printf("NOT  (~p)   = %d\n", ~p);
    printf("LEFT SHIFT  (p << 1) = %d\n", p << 1);
    printf("RIGHT SHIFT (p >> 1) = %d\n\n", p >> 1);

    // 📝 Assignment Operators
    int speed = 10;
    speed += 5;
    speed *= 2;
    printf("🚀 Drone Speed = %d\n", speed);

    // ❓ Ternary Operator
    int temp = 35;
    char *status = (temp > 30) ? "🔥 HOT" : "❄️ COOL";
    printf("Temperature Status: %s\n", status);

    // 📏 sizeof Operator
    printf("\nSize of int: %lu bytes\n", sizeof(int));
    printf("Size of float: %lu bytes\n", sizeof(float));

    // 🔗 Comma Operator
    int i, j;
    i = (j = 3, j + 2);
    printf("\nComma Operator Result: %d\n", i);

    return 0;
}
