#include "ticTacToe.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tic_tac_toe[3][4]={ // Matriz do jogo da velha
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
};
char validPositions[10]={'1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'}; // Guarda as posições que ainda não foram escolhidas
int turn = 0; // guarda a quantidade de turnos

void ticTacToe(){

    while (!wonTicTacToe() && !tie()) { // loop enquanto ninguem tiver ganhado ou empatado
        char playerChosenTile='0'; // variavel para guardar a escolha do player

        printTicTacToe();
        printf("Choose a tile:");
        scanf(" %c", &playerChosenTile);
        putInTicTacToe(playerChosenTile, PLAYER);
        turn++;
        if (wonTicTacToe() != 0){ // Verifica se o player ganhou
            printTicTacToe();
            printf("You Won!");
            break;
        }
        if (tie()){ // Verifica se houve empate
            printTicTacToe();
            printf("It's a Tie!");
            break;
        }
        computerTurn(); // Turno do computador
        turn++;
        if (wonTicTacToe() != 0){ // Verifica se o computador ganhou
            printTicTacToe();
            printf("You Lost!");
            break;
        }
    }
}

void printTicTacToe(){ // Imprime o jogo da velha
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c\n",tic_tac_toe[0][0],tic_tac_toe[0][1],tic_tac_toe[0][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c\n",tic_tac_toe[1][0],tic_tac_toe[1][1],tic_tac_toe[1][2]);
    printf("-----|-----|-----\n");
    printf("  %c  |  %c  |  %c\n",tic_tac_toe[2][0],tic_tac_toe[2][1],tic_tac_toe[2][2]);
    printf("     |     |     \n");
}

void putInTicTacToe(char chosenTile, char playerSimbol){ // Coloca o simbolo no local selecionado
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tic_tac_toe[i][j] == chosenTile)
                tic_tac_toe[i][j] = playerSimbol;
        }
    }
    removeFromValidPositions(chosenTile); // Retira o local escolhido das posições válidas
}

int wonTicTacToe(){ // Verifica se alguem ganhou
    if (tic_tac_toe[0][0] == tic_tac_toe[1][1] && tic_tac_toe[0][0] == tic_tac_toe[2][2]
    || tic_tac_toe[0][1] == tic_tac_toe[1][1] && tic_tac_toe[0][1] == tic_tac_toe[2][1]
    || tic_tac_toe[0][2] == tic_tac_toe[1][1] && tic_tac_toe[0][2] == tic_tac_toe[2][0]
    || tic_tac_toe[1][0] == tic_tac_toe[1][1] && tic_tac_toe[1][0] == tic_tac_toe[1][2])
        return tic_tac_toe[1][1] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[0][0] == tic_tac_toe[0][1] && tic_tac_toe[0][0] == tic_tac_toe[0][2]
    || tic_tac_toe[0][0] == tic_tac_toe[1][0] && tic_tac_toe[0][0] == tic_tac_toe[2][0])
        return tic_tac_toe[0][0] == PLAYER ? 1 : 2;
    else if (tic_tac_toe[2][0] == tic_tac_toe[2][1] && tic_tac_toe[2][0] == tic_tac_toe[2][2]
    || tic_tac_toe[0][2] == tic_tac_toe[1][2] && tic_tac_toe[0][2] == tic_tac_toe[2][2])
        return tic_tac_toe[2][2] == PLAYER ? 1 : 2;

    return 0;
}

int tie(){ // Verifica se houve empate
    return turn == 9;
}

void removeFromValidPositions(char x){ // Retira o local escolhido das posições válidas
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
    int chosenTileIndex = rand() % (mySizeOf(validPositions)); // Escolhe uma posição aleatória entre as disponiveis
    char chosenTile = validPositions[chosenTileIndex];
    putInTicTacToe(chosenTile, COMPUTER);
}

int mySizeOf(char array[]){ // Ve o tamanho do array
    int i=0;
    while (array[i] != '\0'){
        i++;
    }
    return i;
}