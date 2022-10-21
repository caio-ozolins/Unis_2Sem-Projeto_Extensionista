#include "attempt.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void attempt(int* atpt, int maxAttempts, int* victory, double* points){
    int seed = time(0);
    srand(seed);
    int secretNum = (rand() % 100 + 1), guess=0;

    for (int i = 1; i <= maxAttempts; i++) {
        printf("Tentativa %d de %d\n", *atpt, maxAttempts);
        printf("Chute um número positivo entre 0 e 100: \n");
        scanf("%d", &guess);
        if (guess < 0){
            printf("Por favor não digite números negativos.\n");
            continue;
        }

        *victory = guess == secretNum;
        int bigger = guess > secretNum;
        if (*victory) {
            break;
        }
        else if (bigger) {
            printf("Seu chute foi maior que o número secreto.\n\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto.\n\n");
        }
        (*atpt)++;
        double lostPoints = abs(guess - secretNum) / (double)2;
        *points -= lostPoints;
    }
}