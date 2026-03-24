/*

Escreva um programa em C que declare uma matriz de inteiros 2×3, inicialize essa matriz com
valores definidos no código e utilize uma função separada para imprimir os elementos da matriz. A
função deve receber um ponteiro para a matriz como parâmetro.

*/

#include <stdio.h>

int imprimirMatriz(int *ponteiro[2][3]){
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = 0; j < 3; j++){
            printf("[%d][%d] = %d\n", i, j, ponteiro[i][j]);
        }
    }

    return 0;
}

int main(){

    int matriz[2][3] = {{1,2,3}, {4,5,6}};
    imprimirMatriz(&matriz);


}