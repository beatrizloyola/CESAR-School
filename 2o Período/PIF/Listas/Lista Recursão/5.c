/*

Q5
Dada uma matriz quadrada n x n, implemente recursivamente a função int somaLinha(int
m[][MAX], int linha, int col, int n) que retorna a soma de todos os elementos de
uma linha específica. Use-a para imprimir a soma de cada linha da matriz. Não use laços internos
à função

*/

#include <stdio.h>
#define MAX 100

int somaLinha(int m[][MAX], int linha, int col, int n){
    if (col < 0){
        return 0;
    }

    return m[linha][col] + somaLinha(m, linha, col-1, n);
}

int main(){
    int m[3][MAX] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n = 3;
    int col = n - 1;
    int linha = n - 1;

    for (int i = 0; i < n; i++) {
        printf("%d\n", somaLinha(m, i, n - 1, n));
    }

    return 0;
}