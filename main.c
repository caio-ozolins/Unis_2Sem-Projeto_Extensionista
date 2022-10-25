#include <stdio.h>
#include <locale.h>
#include "adivinhacao/level.c"
#include "adivinhacao/attempt.c"
#include "adivinhacao/ordinal.c"

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

    int atpt = 1, maxAttempts, victory;
    double points=1000;

    level(&maxAttempts);

    attempt(&atpt, maxAttempts, &victory, &points);

    char *ordinals[] = { "st", "nd", "rd", "th" };

    printf("Fim de jogo!\n");
    if (victory){
        printf("\n\n");
        printf("          ..::''''''::..\n");
        printf("        .;''          ``;.\n");
        printf("       ::     ::  ::     ::\n");
        printf("      ::      ::  ::      ::      Você venceu na %d%s tentativa\n", atpt, get_ordinal(ordinals, atpt));
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
