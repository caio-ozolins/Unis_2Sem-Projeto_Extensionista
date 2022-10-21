#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "level.c"

int main(){
    setlocale(LC_ALL, "Portuguese");

    printf("\n\n");
    printf("          P  /_\\  P\n");
    printf("         /_\\_|_|_/_\\\n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao\n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!\n");
    printf("    |\" \"  |  |_|  |\"  \" |\n");
    printf("    |_____| ' _ ' |_____|\n");
    printf("          \\__|_|__/\n");
    printf("\n\n");

    int seed = time(0);
    srand(seed);
    int secretNum = (rand() % 100 + 1), guess, attempt = 1, maxAttempts, victory = 0, difficulty;
    double points=1000;

    level(&difficulty, &maxAttempts);

    for (int i = 1; i <= maxAttempts; i++) {
        printf("Tentativa %d de %d\n", attempt, maxAttempts);
        printf("Chute um número positivo entre 0 e 100: \n");
        scanf("%d", &guess);
        if (guess < 0){
            printf("Por favor não digite números negativos.\n");
            continue;
        }

        victory = guess == secretNum;
        int bigger = guess > secretNum;
        if (victory) {
            break;
        }
        else if (bigger) {
            printf("Seu chute foi bigger que o número secreto.\n\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto.\n\n");
        }
        attempt++;
        double lostPoints = abs(guess - secretNum) / (double)2;
        points -= lostPoints;
    }
    printf("Fim de jogo!\n");
    if (victory){
        printf("\n\n");
        printf("          ..::''''''::..\n");
        printf("        .;''          ``;.\n");
        printf("       ::     ::  ::     ::\n");
        printf("      ::      ::  ::      ::      Você venceu na %dª tentativa\n", attempt);
        printf("      ::  .:' ::  :: `:.  ::      Total de points: %.1f\n", points);
        printf("      ::   :          :   ::\n");
        printf("       ::  `:.      .:'  ::\n");
        printf("        `;.. ``::::'' ..;'\n");
        printf("          ``::,,,,,,::''\n");
        printf("\n\n");
    } else{
        printf("\n\n");
        printf("Você errou, tente novamente\n");
        printf("    \\|/ ____ \\|/\n");
        printf("     @~/ ,. \\~@\n");
        printf("    /_( \\__/ )_\\\n");
        printf("       \\__U_/\n");
        printf("\n\n");
    }

    return 0;
}
