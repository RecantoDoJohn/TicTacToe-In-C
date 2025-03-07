#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "jogador.h"

int main() {
    Tabuleiro tabuleiro;
    Jogador jogadores[2];
    int quantJogadores = 2;

    definirJogador(&jogadores[0], 'X');
    definirJogador(&jogadores[1], 'O');


    initTabuleiro(&tabuleiro);

    while (tabuleiro.acontecendo == 1) {
        for (int i = 0; i < quantJogadores; i++) {
            int x, y;
            mostrarTabuleiro(&tabuleiro);
            printf("Vez de Jogador '%c'\n", jogadores[i].simbolo);

            printf("Posicao x: ");
            scanf("%d", &x);

            printf("Posicao y: ");
            scanf("%d", &y);

            i = i - atribuirCasa(&tabuleiro, x, y, jogadores[i].simbolo);

            if (verificarVitoria(&tabuleiro, jogadores[i].simbolo) == 1) {
                printf("terminou\n");
                break;
            }
        }
        system("cls");
    }


}