/*

Ler matriz e encontrar o maior elemento
Escreva um programa que:
• leia n e m
• aloque dinamicamente uma matriz n x m
• leia os valores do usuário
• determine e imprima o maior valor da matriz
• libere a memória corretamente

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas, colunas, i, j, k;
    printf("Linhas: ");
    scanf("%d", &linhas);
    printf("Colunas: ");
    scanf("%d", &colunas);

    if (linhas <= 0 || colunas <= 0){
        printf("Dimensões inválidas.\n");
        return 1;
    }

    int** matriz = calloc(linhas, sizeof(int*));
    if (matriz == NULL){
        return 1;
    }
    for (i = 0; i<linhas; i++){
        matriz[i] = calloc(colunas, sizeof(int));
        if (matriz[i] == NULL){
            for(k = 0; k < i; k++){
                free(matriz[k]);
            }
            free(matriz);
            return 1;
        }
    }

    for(i = 0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            int valor;
            printf("[%d][%d] = ", i, j);
            scanf("%d", &valor);
            matriz[i][j] = valor;
        }
    }

    int maior = matriz[0][0];

    for(i = 0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            if (matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }

    printf("Maior valor da matriz: %d", maior);

    for(i=0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);

    printf("\n");
    return 0;
}