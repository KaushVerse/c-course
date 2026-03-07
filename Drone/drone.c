#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned int battery = 15;
    int altitude = 500;

    printf("🔋 Battery = %u%% (Max possible: %u)\n", battery, UINT_MAX);
    printf("⛰️ Altitude = %d meters (Safe range: %d to %d)\n",
           altitude, INT_MIN, INT_MAX);

    if (altitude > INT_MAX || altitude < INT_MIN)
    {
        printf("⚠️ Altitude value out of range!\n");
    }
    else
    {
        printf("✅ Altitude within safe integer range.\n");
    }

    return 0;
}
