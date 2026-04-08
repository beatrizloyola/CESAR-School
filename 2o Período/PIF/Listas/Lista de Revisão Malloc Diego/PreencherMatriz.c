/*

1. Criar e preencher matriz dinamicamente
Escreva um programa que:
• leia dois inteiros n e m
• aloque dinamicamente uma matriz n x m
• preencha a matriz com valores de 1 até n*m
• imprima os elementos
• libere a memória alocada

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas, colunas;
    int i, j;

    printf("Número de linhas: ");
    scanf("%d", &linhas);
    printf("Número de colunas: ");
    scanf("%d", &colunas);

    int **matriz = (int **)calloc(linhas, sizeof(int*));
    for(i=0; i<linhas; i++){
        matriz[i] = (int *)calloc(colunas, sizeof(int));
    }

    int valor = 1;
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            matriz[i][j] = valor;
            valor++;
        }
    }

    for(i=0; i<linhas; i++){
        printf("\n");
        for(j=0; j<colunas; j++){
            printf("%d\t", matriz[i][j]);
        }
    }

    for(i=0; i<linhas; i++){
        free(matriz[i]);
    }

    printf("\n");
    return 0;
}