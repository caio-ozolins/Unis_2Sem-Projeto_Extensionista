#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#define PLAYER 'X'
#define COMPUTER 'O'

void printTicTacToe();
void putInTicTacToe(char chosenTile, char playerSimbol);
int wonTicTacToe();
int tie();
void removeFromValidPositions(char x);
void swap(char* x, char* y);
void computerTurn();
int mySizeOf(char array[]);

#endif //TIC_TAC_TOE_TICTACTOE_H
