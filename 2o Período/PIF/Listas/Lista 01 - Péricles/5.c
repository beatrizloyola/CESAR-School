/*
5) Difícil — Vetor + Matriz: coluna com menor soma ponderada
A) Implemente uma função que receba:
● um inteiro N,
● uma matriz quadrada N x N de reais,
● e um vetor de reais P de tamanho N.

Para cada coluna j, calcule a soma ponderada:

A função deve retornar o índice da coluna que possui a menor soma ponderada.
Regras:
● Em caso de empate, retornar a primeira coluna encontrada.
● Considere N > 0.

B) Implemente uma função main() que:
1. define uma matriz N x N de reais já preenchida;
2. define um vetor de pesos P já preenchido;
3. chama a função;
4. imprime o índice da coluna retornada.
*/

#include <stdio.h>

int funcao(int n, double matriz[n][n], double vetor[n]){
    int i, j;
    double menorSoma;
    int menorSomaIndice = 0;
    for (j = 0; j < n; j++){
        double somaAtual = 0;
        for (i = 0; i < n; i++){
            somaAtual += matriz[i][j] * vetor[i];
        }
        if (j == 0){
            menorSoma = somaAtual;
        } else if (somaAtual < menorSoma){
            menorSoma = somaAtual;
            menorSomaIndice = j;
        }
    }

    return menorSomaIndice;
}

int main(){
    double matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    double vetor[3] = {2, 3, 0};
    int resultado = funcao(3, matriz, vetor);
    printf("%d", resultado);

    return 0;
}