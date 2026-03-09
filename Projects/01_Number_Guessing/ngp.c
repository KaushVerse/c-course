#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int number, guess;
    int attempts, maxAttempts;
    int difficulty;
    int score = 0;
    int playAgain = 1;
    int players;
    int player;

    srand(time(0));

    printf("🎮 NUMBER GUESSING GAME\n");

    printf("\nSelect number of players (1 or 2): ");
    scanf("%d", &players);

    while (playAgain)
    {

        printf("\nSelect Difficulty Level\n");
        printf("1️⃣ Easy (1-50)\n");
        printf("2️⃣ Medium (1-100)\n");
        printf("3️⃣ Hard (1-200)\n");

        scanf("%d", &difficulty);

        int range;

        if (difficulty == 1)
        {
            range = 50;
            maxAttempts = 10;
        }
        else if (difficulty == 2)
        {
            range = 100;
            maxAttempts = 7;
        }
        else
        {
            range = 200;
            maxAttempts = 5;
        }

        number = rand() % range + 1;

        clock_t start = clock();

        for (player = 1; player <= players; player++)
        {

            printf("\n👤 Player %d Turn\n", player);

            attempts = 0;

            while (attempts < maxAttempts)
            {

                printf("Guess the number (1-%d): ", range);
                scanf("%d", &guess);

                attempts++;

                if (guess > number)
                    printf("📉 Too High!\n");

                else if (guess < number)
                    printf("📈 Too Low!\n");

                else
                {
                    printf("🎉 Correct Guess!\n");

                    score += (maxAttempts - attempts + 1) * 10;

                    break;
                }
            }

            if (attempts == maxAttempts)
                printf("❌ Out of attempts! Number was %d\n", number);
        }

        clock_t end = clock();

        double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\n⏱ Time Taken: %.2f seconds\n", timeTaken);

        printf("🏆 Current Score: %d\n", score);

        printf("\nPlay Again? (1 = Yes / 0 = No): ");
        scanf("%d", &playAgain);
    }

    printf("\n🎯 Final Score: %d\n", score);

    printf("Thanks for playing!\n");

    return 0;
}