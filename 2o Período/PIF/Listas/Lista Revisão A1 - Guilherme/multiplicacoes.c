/*
Faça um programa que leia uma matriz 3x3 e exiba a multiplicação de
todos os elementos da diagonal principal,secundária e da coluna central
*/

#include <stdio.h>

void funcao(int matriz[3][3]){
    int multPrincipal = 1;
    int multSecundaria = 1;
    int multCentral = 1;


    printf("Diagonal principal: \n");
    for(int i = 0; i < 3; i++){
        printf("[%d][%d]: %d\n", i, i, matriz[i][i]);
        multPrincipal *= matriz[i][i];
    }
    printf("Produto: %d\n\n", multPrincipal);

    printf("Diagonal secundária: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if ((i + j) == 2){
                printf("[%d][%d]: %d\n", i, j, matriz[i][j]);
                multSecundaria *= matriz[i][j];
            }
        }
    }
    printf("Produto: %d\n\n", multSecundaria);

    printf("Coluna central: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 1){
                printf("[%d][%d]: %d\n", i, j, matriz[i][j]);
                multCentral *= matriz[i][j];
            }
        }
    }
    printf("Produto: %d", multCentral);
}

int main(){
    int matriz[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    funcao(matriz);

    return 0;
}