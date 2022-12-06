#include <stdio.h>
#include "hangmanGame.h"
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void hangmanGame() {

    char secretWord[WORD_LENGTH];
    char attempts[26];
    int qtyGuesses = 0;

    printf("\n\n");
    printf("+==========================+\n");
    printf(":      Welcome to the      :\n");
    printf(":       Hangman Game!      :\n");
    printf("+==========================+\n");
    printf("\n\n");

    chooseWord(secretWord);

    do {
        drawHangman(qtyGuesses, secretWord, attempts);
        playerAttempt(&qtyGuesses, attempts);
    } while (!won(qtyGuesses, secretWord, attempts) && !hanged(qtyGuesses, secretWord, attempts));

    if (won(qtyGuesses, secretWord, attempts)){
        printf("+=========================+\n");
        printf(":     Congratulations     :\n");
        printf(":         You won         :\n");
        printf("+=========================+\n");
        printf("The word was %s\n\n", secretWord);
    } else {
        printf("+==========================+\n");
        printf(":   You lost, try again.   :\n");
        printf("+==========================+\n");
        printf("The word was %s\n\n", secretWord);
    }

    char x;
    printf("Do you want to add a word to the database? (Y/N)\n");
    scanf(" %c", &x);
    x = toupper(x);

    if (x == 'Y'){
        addWord();
    }

}

void addWord(){ // Adiciona uma nova palavra no banco de dados

    // Pergunta qual a nova palavra
    char newWord[WORD_LENGTH];
    printf("Type the new word:\n");
    scanf("%s", newWord);
    strtoupper(newWord);

    // Abre o arquivo com a lista de palavras
    FILE* f;
    f = fopen("Words.txt", "r+");

    // Imprime erro caso o arquivo não abra
    if (f == 0){
        printf("Database unavailable\n\n");
        exit(1);
    }

    // Le quantas palavras tem no arquivo
    int qtyWords = 0;
    fscanf(f, "%d", &qtyWords);
    qtyWords++;

    // Adiciona a nova palavra no banco de dados
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", qtyWords);
    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", newWord);

    // Fecha o arquivo
    fclose(f);
}

int alreadyGuessed(char letter, int qtyGuesses, char *attempts) { // Verifica se a letra já foi chutada
    int found = 0;

    for (int i = 0; i < qtyGuesses; ++i) {
        if (attempts[i] == letter){
            found = 1;
            break;
        }
    }
    return found;
}

void chooseWord(char* secretWord){

    // Abre o arquivo com a lista de palavras
    FILE* f;
    f = fopen("Words.txt", "r");

    // Imprime erro caso o arquivo não abra
    if (f == 0){
        printf("Database unavailable\n\n");
        exit(1);
    }

    // Le quantas palavras tem no arquivo
    int qtyWords = 0;
    fscanf(f, "%d", &qtyWords);

    // Escolhe uma palavra aleatória
    srand(time(0));
    int numRand = rand() % qtyWords;
    for (int i = 0; i <= numRand; i++) {
        fscanf(f, "%s", secretWord);
    }

    // Fecha o arquivo
    fclose(f);
}

void drawHangman(int qtyGuesses, char* secretWord, char* attempts){

    // Verifica a qtd de erros
    int qtyMistakes = wrongGuesses(qtyGuesses, secretWord, attempts);

    // Imprime a forca
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (qtyMistakes >=1 ? '(' : ' '), (qtyMistakes >=1 ? '_' : ' '), (qtyMistakes >=1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (qtyMistakes >=3 ? '\\' : ' '), (qtyMistakes >=2 ? '|' : ' '), (qtyMistakes >=3 ? '/' : ' '));
    printf(" |       %c     \n", (qtyMistakes >=2 ? '|' : ' '));
    printf(" |      %c %c   \n", (qtyMistakes >=4 ? '/' : ' '), (qtyMistakes >=4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    printSecretWord(qtyGuesses, secretWord, attempts);
}

int hanged(int qtyGuesses, char* secretWord, char* attempts){// Verifica se o jogador foi "enforcado"
    return wrongGuesses(qtyGuesses, secretWord, attempts) >= 4;
}

void playerAttempt(int* qtyGuesses, char* attempts){ // Chute do jogador
    char guess;
    printf("Type a letter:");
    scanf(" %c", &guess);
    guess = toupper(guess);

    attempts[*qtyGuesses] = guess;
    (*qtyGuesses)++;
}

void strtoupper(char s[]){ // Converte uma string para maiúsculo
    int i = 0;
    while(s[i] != '\0'){
        s[i] = toupper(s[i]);
        i++;
    }
}

int won(int qtyGuesses, char* secretWord, char* attempts){// Verifica se o jogador acertou a palavra
    for (int i = 0; i < strlen(secretWord); ++i) {
        if (!alreadyGuessed(secretWord[i], qtyGuesses, attempts)){
            return 0;
        }
    }
    return 1;
}

int wrongGuesses(int qtyGuesses, char* secretWord, char* attempts){ // Verifica a qtd de erros
    int mistakes=0;
    for (int i = 0; i < qtyGuesses; ++i) {
        int equal = 0;
        for (int j = 0; j < strlen(secretWord); ++j) {
            if (attempts[i] == secretWord[j]){
                equal = 1;
                break;
            }
        }
        if (!equal){mistakes++;}
    }
    return mistakes;
}

void printSecretWord(int qtyGuesses, char* secretWord, char* attempts){ // Imprime a palavra secreta
    for (int i = 0; i < strlen(secretWord); i++) {

        int found = alreadyGuessed(secretWord[i], qtyGuesses, attempts);
        if(found){
            printf("%c ", secretWord[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}