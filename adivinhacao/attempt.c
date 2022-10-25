#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void attempt(int* atpt, int maxAttempts, int* victory){
    int seed = time(0);
    srand(seed);
    int secretNum = (rand() % 101), guess=0, lguess=0, hguess=100;

    for (int i = 1; i <= maxAttempts; i++) {
        printf("Attempt %d of %d.\n", *atpt, maxAttempts);
        printf("Guess a number between %d and %d:\n", lguess, hguess);
        scanf("%d", &guess);
        if (guess < lguess || guess > hguess){
            printf("Please enter a number between %d and %d.\n", lguess, hguess);
            continue;
        }

        *victory = guess == secretNum;
        int bigger = guess > secretNum;
        if (*victory) {
            break;
        } else {
            if (bigger) {
                if (guess < hguess) { hguess = guess; }
            } else {
                if (guess > lguess) { lguess = guess; }
            }
            printf("The secret number is between %d and %d\n\n", lguess, hguess);
        }
        (*atpt)++;
    }
}