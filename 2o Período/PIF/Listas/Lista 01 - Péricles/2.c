/*
2) Fácil/Médio — Matriz: verificar se todas as linhas estão em ordem
crescente
A) Implemente uma função que receba um inteiro N e uma matriz quadrada N x N de inteiros
como parâmetros.
A função deve retornar:

● 1, se todas as linhas da matriz estiverem em ordem estritamente crescente da
esquerda para a direita;
● 0, caso contrário.

Regras:
● Considere N > 0.
● Uma linha é estritamente crescente se, para toda coluna válida j, vale: mat[i][j] <
mat[i][j+1].

Exemplo:

Retorno: 1
B) Implemente uma função main() que:
1. define uma matriz N x N já preenchida;
2. chama a função;
3. imprime o resultado.
*/

#include <stdio.h>

int funcao(int n, int matriz[n][n]){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < n - 1; j++){
            printf("[%d][%d]: ", i, j);
            if (matriz[i][j] < matriz[i][j+1]){
                printf("até aqui de boa\n");
            } else {
                printf("vishkk\n");
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int matriz1[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int matriz2[4][4] = {{16,15,14,13}, {12,11,10,9}, {8,7,6,5}, {4,3,2,1}};
    printf("%d %d", funcao(4, matriz1), funcao(4, matriz2)); 

    return 0;
}