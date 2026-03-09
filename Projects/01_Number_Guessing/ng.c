#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int number, guess, attempts = 0;

    // Random number generator initialize
    srand(time(0));

    // Random number between 1 - 100
    number = rand() % 100 + 1;

    printf("🎯 Welcome to Number Guessing Game!\n");
    printf("Guess a number between 1 and 100\n");

    while (1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > number)
        {
            printf("📈 Too High! Try again.\n");
        }
        else if (guess < number)
        {
            printf("📉 Too Low! Try again.\n");
        }
        else
        {
            printf("🎉 Correct! You guessed in %d attempts.\n", attempts);
            break;
        }
    }

    return 0;
}