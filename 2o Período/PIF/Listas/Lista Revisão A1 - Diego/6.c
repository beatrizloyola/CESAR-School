/*
6) (Difícil) Implemente uma função que receba um inteiro N e uma matriz N x N de inteiros e
retorne o índice da coluna com maior soma. Em caso de empate, retornar a primeira encontrada.
Depois, implemente a main() que imprime o resultado.
*/

#include <stdio.h>

int somaMaiorColuna(int n, int matriz[n][n]);

int main(){
    int matriz[3][3] = {{0, 0, 3}, {1, 0, 4}, {0, 2, 5}};
    printf("%d", somaMaiorColuna(3, matriz));

    return 0;
}

int somaMaiorColuna(int n, int matriz[n][n]){
    int i, j, x;
    int soma;
    int maiorSoma = 0;
    int maiorColuna = 0;

    for(x = 0; x < n; x++){
        maiorSoma += matriz[x][0];
    }

    for(j = 0; j < n; j++){
        soma = 0;
        for(i = 0; i < n; i++){
            soma += matriz[i][j];
        }
        if(soma > maiorSoma){
            maiorSoma = soma;
            maiorColuna = j;
        }
    }
    return maiorColuna;
}