#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

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
    int secretNum = (rand() % 100 + 1), guess, try = 1, tryNum, victory = 0, lvl;
    double pontos=1000;

    printf("Qual o nível de dificuldade?\n");
    printf("1.Fácil 2.Médio 3.Difícil\n\n");
    printf("Escolha:");
    scanf("%d", &lvl);
    switch (lvl) {
    case 1:
            tryNum=12;
            break;
        case 2:
            tryNum=9;
            break;
        default:
            tryNum=6;
        break;
    }

    for (int i = 1; i <= tryNum; i++) {
        printf("Tentativa %d de %d\n", try, tryNum);
        printf("Chute um número positivo entre 0 e 100: \n");
        scanf("%d", &guess);
        if (guess < 0){
            printf("Por favor não digite números negativos.\n");
            continue;
        }

        victory = guess == secretNum;
        int maior = guess > secretNum;
        if (victory) {
            break;
        }
        else if (maior) {
            printf("Seu chute foi maior que o número secreto.\n\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto.\n\n");
        }
        try++;
        double pontosPerdidos = abs(guess - secretNum) / (double)2;
        pontos -= pontosPerdidos;
    }
    printf("Fim de jogo!\n");
    if (victory){
        printf("\n\n");
        printf("          ..::''''''::..\n");
        printf("        .;''          ``;.\n");
        printf("       ::     ::  ::     ::\n");
        printf("      ::      ::  ::      ::      Você venceu na %dª tentativa\n", try);
        printf("      ::  .:' ::  :: `:.  ::      Total de pontos: %.1f\n", pontos);
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
