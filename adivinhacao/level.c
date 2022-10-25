#include <stdio.h>

void level(int* maxAttempts){
    int difficulty;
    printf("+--------------------------+\n");
    printf(":  1.Easy 2.Medium 3.Hard  :\n");
    printf("+--------------------------+\n\n");
    printf("Choose the difficulty level.\n");
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