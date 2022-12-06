#include <stdio.h>
#include "main.h"

int main(){
    int game=0;

    printf("\n\n+====================+\n");
    printf(":  1. Guessing Game  :\n");
    printf(":  2. Hangman Game   :\n");
    printf("+====================+\n\n");
    scanf("%d", &game);

    switch (game) {
        case 1:
            guessingGame();
            break;
        case 2:
            hangmanGame();
            break;
        default:
            printf("Game not found");
    }

    return 0;
}
