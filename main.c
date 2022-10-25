#include <stdio.h>
#include "adivinhacao/level.c"
#include "adivinhacao/attempt.c"
#include "adivinhacao/ordinal.c"

int main(){

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

    return 0;
}
