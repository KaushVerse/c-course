#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char password[100];
    int length;

    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    printf("🔐 PASSWORD STRENGTH CHECKER\n");

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++)
    {

        if (isupper(password[i]))
            hasUpper = 1;

        else if (islower(password[i]))
            hasLower = 1;

        else if (isdigit(password[i]))
            hasDigit = 1;

        else
            hasSpecial = 1;
    }

    printf("\n📊 Password Analysis\n");

    if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial)
    {
        printf("✅ Strong Password\n");
    }
    else
    {
        printf("❌ Weak Password\n");
    }

    return 0;
}