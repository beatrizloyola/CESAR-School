#include <stdio.h>

#define MAXR 200
#define MAXC 200

typedef struct {
    int soma;
    int linha;
    int coluna;
} Resultado;

Resultado funcao(int R, int C, int K, int A[MAXR][MAXC]) {
    int x, y, i, j;
    int somaAtual;
    int maiorSoma = 0;
    int linhaVencedora = 0;
    int colunaVencedora = 0;
    int primeira = 1;

    for (x = 0; x <= R - K; x++) {
        for (y = 0; y <= C - K; y++) {

            somaAtual = 0;

            for (i = 0; i < K; i++) {
                for (j = 0; j < K; j++) {
                    somaAtual += A[x + i][y + j];
                }
            }

            if (primeira ||
                somaAtual > maiorSoma ||
                (somaAtual == maiorSoma &&
                 (x < linhaVencedora ||
                 (x == linhaVencedora && y < colunaVencedora)))) {

                maiorSoma = somaAtual;
                linhaVencedora = x;
                colunaVencedora = y;
                primeira = 0;
            }
        }
    }

    Resultado r;
    r.soma = maiorSoma;
    r.linha = linhaVencedora;
    r.coluna = colunaVencedora;

    return r;
}

int main() {
    int R, C, K;
    int A[MAXR][MAXC];

    if (scanf("%d %d %d", &R, &C, &K) != 3) return 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    Resultado res = funcao(R, C, K, A);

    printf("%d %d %d\n", res.soma, res.linha, res.coluna);

    return 0;
}