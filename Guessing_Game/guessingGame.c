#include "guessingGame.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guessingGame(){

    printf("\n\n");
    printf("+==========================+\n");
    printf(":      Welcome to the      :\n");
    printf(":      Guessing Game!      :\n");
    printf("+==========================+\n");
    printf("\n\n");

    int atpt = 1, maxAttempts, victory;

    level(&maxAttempts);

    attempt(&atpt, maxAttempts, &victory);

    char *ordinals[] = { "st", "nd", "rd", "th" };

    if (victory){
        printf("+=========================+\n");
        printf(":     Congratulations     :\n");
        printf(": You won on the %d%s try. :\n", atpt, get_ordinal(ordinals, atpt));
        printf("+=========================+\n");
    } else{
        printf("+==========================+\n");
        printf(":   You lost, try again.   :\n");
        printf("+==========================+\n");
    }
}
void attempt(int* atpt, int maxAttempts, int* victory){
    int seed = time(0);
    srand(seed);
    int secretNum = (rand() % 101) /* Seleciona um numero aleatorio entre 0 e 100 */, guess=0, lguess=0, hguess=100;

    for (int i = 1; i <= maxAttempts; i++) {
        printf("Attempt %d of %d.\n", *atpt, maxAttempts); // Imprime quantas tentativas restam
        printf("Guess a number between %d and %d:\n", lguess, hguess);
        scanf("%d", &guess);
        if (guess < lguess || guess > hguess){ // Verifica se o jogador colocou um número válido
            printf("Please enter a number between %d and %d.\n", lguess, hguess);
            continue;
        }

        *victory = guess == secretNum; // Verifica se o jogador ganhou
        int bigger = guess > secretNum; // Verifica se o chute foi maior que o número secreto
        if (*victory) { // Se o jogador venceu acaba o jogo
            break;
        } else { // Atualiza o range do número secreto
            if (bigger) {
                if (guess < hguess) { hguess = guess; }
            } else {
                if (guess > lguess) { lguess = guess; }
            }
            printf("The secret number is between %d and %d\n\n", lguess, hguess);
        }
        (*atpt)++; // Atualiza o número de tentativas
    }
}

void level(int* maxAttempts){ // Escolhe o nivel de dificuldade
    int difficulty;
    printf("+--------------------------+\n");
    printf(":  1.Easy 2.Medium 3.Hard  :\n");
    printf("+--------------------------+\n\n");
    printf("Choose the difficulty level.\n");
    x:
    scanf("%d", &difficulty);
    switch (difficulty) {
        case 1:
            *maxAttempts=12;
            break;
        case 2:
            *maxAttempts=9;
            break;
        case 3:
            *maxAttempts=6;
            break;
        default:
            printf("Invalid choice, try again:\n");
            goto x;
    }
}