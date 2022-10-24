#include "../main.h"
#include <stdio.h>

void level(int* maxAttempts){
    int difficulty;
    printf("Qual o nível de dificuldade?\n");
    printf("1.Fácil 2.Médio 3.Difícil\n\n");
    printf("Escolha:");
    scanf("%d", &difficulty);
    switch (difficulty) {
        case 1:
            *maxAttempts=12;
            break;
        case 2:
            *maxAttempts=9;
            break;
        default:
            *maxAttempts=6;
            break;
    }
}