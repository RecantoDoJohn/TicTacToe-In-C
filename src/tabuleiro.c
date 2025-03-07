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

int verificarVitoria(Tabuleiro *tabuleiro, char simbolo) {
    if ((tabuleiro->casas[0][0] == simbolo && tabuleiro->casas[1][1] == simbolo && tabuleiro->casas[2][2] == simbolo) || 
        (tabuleiro->casas[2][0] == simbolo && tabuleiro->casas[1][1] == simbolo && tabuleiro->casas[0][2] == simbolo)) {
            tabuleiro->acontecendo = 0;
            return 1;
        }

    // verificar fileiras horizontais
    for (int x = 0; x < tabuleiro->tamanho; x++) {
        if (tabuleiro->casas[x][0] == simbolo && tabuleiro->casas[x][1] == simbolo && tabuleiro->casas[x][2] == simbolo) {
            tabuleiro->acontecendo = 0;
            return 1;
        }
        if (tabuleiro->casas[0][x] == simbolo && tabuleiro->casas[1][x] == simbolo && tabuleiro->casas[2][x] == simbolo) {
            tabuleiro->acontecendo = 0;
            return 1;
        }
    }

    return 0;
}