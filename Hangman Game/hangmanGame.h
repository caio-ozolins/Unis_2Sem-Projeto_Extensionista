#ifndef TESTE_HANGMANGAME_H
#define TESTE_HANGMANGAME_H

#define WORD_LENGTH 20

void addWord();
int alreadyGuessed(char letter, int qtyGuesses, char* attempts);
void chooseWord(char* secretWord);
void drawHangman(int qtyGuesses, char* secretWord, char* attempts);
int hanged(int qtyGuesses, char* secretWord, char* attempts);
void playerAttempt(int* qtyGuesses, char* attempts);
int won(int qtyGuesses, char* secretWord, char* attempts);
int wrongGuesses(int qtyGuesses, char* secretWord, char* attempts);
void strtoupper(char s1[]);
void printSecretWord(int qtyGuesses, char* secretWord, char* attempts);

#endif //TESTE_HANGMANGAME_H