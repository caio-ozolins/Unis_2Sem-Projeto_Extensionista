#include "ticTacToe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tic_tac_toe[3][4]={ // Matriz do jogo da velha
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
};
char validPositions[10]={'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'}; // Guarda as posições q ainda não foram escolhidas
int turn = 0; // guarda

void ticTacToe(){

    while (!wonTicTacToe() && !tie()) {
        char playerChosenTile='0';

        printTicTacToe();
        printf("Choose a tile:");
        scanf(" %c", &playerChosenTile);
        putInTicTacToe(playerChosenTile, PLAYER);
        turn++;
        if (wonTicTacToe() != 0){
            printTicTacToe();
            printf("You Won!");
            break;
        }
        if (tie()){
            printTicTacToe();
            printf("It's a Tie!");
            break;
        }
        computerTurn();
        turn++;
        if (wonTicTacToe() != 0){
            printTicTacToe();
            printf("You Lost!");
            break;
        }
    }
}

void printTicTacToe(){
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n",tic_tac_toe[0][0],tic_tac_toe[0][1],tic_tac_toe[0][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c\n",tic_tac_toe[1][0],tic_tac_toe[1][1],tic_tac_toe[1][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c\n",tic_tac_toe[2][0],tic_tac_toe[2][1],tic_tac_toe[2][2]);
    printf("     |     |     \n");
}

void putInTicTacToe(char chosenTile, char playerSimbol){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tic_tac_toe[i][j] == chosenTile)
                tic_tac_toe[i][j] = playerSimbol;
        }
    }
    removeFromArray(chosenTile);
}

int wonTicTacToe(){
    int x;
    if (tic_tac_toe[0][0] == tic_tac_toe[0][1] && tic_tac_toe[0][0] == tic_tac_toe[0][2])
        return tic_tac_toe[0][0] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[1][0] == tic_tac_toe[1][1] && tic_tac_toe[1][0] == tic_tac_toe[1][2])
        return tic_tac_toe[1][0] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[2][0] == tic_tac_toe[2][1] && tic_tac_toe[2][0] == tic_tac_toe[2][2])
        return tic_tac_toe[2][0] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[0][0] == tic_tac_toe[1][0] && tic_tac_toe[0][0] == tic_tac_toe[2][0])
        return tic_tac_toe[0][0] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[0][1] == tic_tac_toe[1][1] && tic_tac_toe[0][1] == tic_tac_toe[2][1])
        return tic_tac_toe[0][1] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[0][2] == tic_tac_toe[1][2] && tic_tac_toe[0][2] == tic_tac_toe[2][2])
        return tic_tac_toe[0][2] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[0][0] == tic_tac_toe[1][1] && tic_tac_toe[0][0] == tic_tac_toe[2][2])
        return tic_tac_toe[0][0] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[0][2] == tic_tac_toe[1][1] && tic_tac_toe[0][2] == tic_tac_toe[2][0])
        return tic_tac_toe[0][2] == PLAYER ? 1 : 2;

    return 0;
}

int tie(){
    return turn == 9;
}

void removeFromArray(char x){
    int sizeArray = mySizeOf(validPositions);
    for (int i = 0; i < sizeArray; ++i) {
        if (validPositions[i] == x){
            for (int j = i; j < sizeArray; ++j) {
                swap(&validPositions[j], &validPositions[j+1]);
            }
        }
    }
}

void swap(char* x, char* y){ // Troca dois valores de lugar
    char temp = *x;
    *x = *y;
    *y = temp;
}

void computerTurn(){
    srand(time(NULL));
    int chosenTileIndex = rand() % (mySizeOf(validPositions));
    char chosenTile = validPositions[chosenTileIndex];
    putInTicTacToe(chosenTile, COMPUTER);
}

int mySizeOf(char array[]){
    int i=0;
    while (array[i] != '\0'){
        i++;
    }
    return i;
}