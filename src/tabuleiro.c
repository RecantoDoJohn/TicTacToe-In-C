#include <stdio.h>
#include "tabuleiro.h"


void initTabuleiro(Tabuleiro *tabuleiro){
    tabuleiro->tamanho = 3;
    tabuleiro->acontecendo = 1;

    for (int x = 0; x < tabuleiro->tamanho; x++) {
        for (int y = 0; y < tabuleiro->tamanho; y++) {
            tabuleiro->casas[x][y] = ' ';
        }
    }
}

void mostrarTabuleiro(Tabuleiro *tabuleiro) {
    for (int x = 0; x < tabuleiro->tamanho; x++) {
        for (int y = 0; y < tabuleiro->tamanho; y++) {
            printf("|%c|", tabuleiro->casas[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

int atribuirCasa(Tabuleiro *tabuleiro, int x, int y, char simbolo) {
    char* casa = &tabuleiro->casas[y][x];
    if (0 <= x && x < 3 && 0 <= y && y < 3 && *casa == ' ') {
        tabuleiro->casas[y][x] = simbolo;
        return 0;
    } else {
        return 1;
    }
}