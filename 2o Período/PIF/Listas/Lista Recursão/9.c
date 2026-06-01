/*

Q9
Implemente recursivamente a função int maiorElemento(int m[][MAX], int lin, int
col, int n) que percorre uma matriz quadrada n x n e retorna o maior elemento. A travessia
deve avançar coluna por coluna e, ao chegar na última coluna, passar para a próxima linha.
Nenhum laço é permitido.

*/

#include <stdio.h>

#define MAX 100

int maiorElemento(int m[][MAX], int lin, int col, int n) {
    // último elemento da matriz
    if (lin == n - 1 && col == n - 1) {
        return m[lin][col];
    }

    int maiorResto;

    // próxima posição
    if (col == n - 1) {
        maiorResto = maiorElemento(m, lin + 1, 0, n);
    } else {
        maiorResto = maiorElemento(m, lin, col + 1, n);
    }

    if (m[lin][col] > maiorResto) {
        return m[lin][col];
    }

    return maiorResto;
}

int main() {
    int m[3][MAX] = {
        {1, 2, 3},
        {10, 5, 6},
        {7, 8, 9}
    };

    printf("%d\n", maiorElemento(m, 0, 0, 3));

    return 0;
}