// Crie um programa que leia uma matriz 3x3 e exiba todos os elementos da diagonal principal.

#include <stdio.h>

void diagonalPrincipal(int matriz[3][3]){
    int i;
    for (i = 0; i < 3; i++){
            printf("%d ", matriz[i][i]);
        }
}

int main(){
    int matrizTeste[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    diagonalPrincipal(matrizTeste);
    return 0;
}