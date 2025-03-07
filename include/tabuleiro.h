
#define TABULEIRO_H
typedef struct {
    char casas[3][3];
    int tamanho; 
    int acontecendo;
} Tabuleiro;

void initTabuleiro(Tabuleiro *tabuleiro);

void mostrarTabuleiro(Tabuleiro *tabuleiro);

int atribuirCasa(Tabuleiro *tabuleiro, int x, int y, char simbolo);

int verificarVitoria(Tabuleiro *tabuleiro, char simbolo);
