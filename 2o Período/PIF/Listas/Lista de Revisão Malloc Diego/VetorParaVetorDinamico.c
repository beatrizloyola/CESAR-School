/*

Escreva um programa que:
• leia um inteiro n
• aloque dinamicamente dois vetores de tamanho n
• leia os valores do primeiro vetor
• copie os valores para o segundo vetor
• imprima o segundo vetor
• libere toda a memória usada
Restrições:
• faça a cópia manualmente com laço
• não use memcpy

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i;
    printf("Tamanho dos vetores: ");
    scanf("%d", &n);

    if(n<=0){
        printf("Tamanho inválido.");
        return 1;
    }

    int *vetor1 = malloc(n*sizeof(int));
    if (vetor1 == NULL){
        printf("Erro na alocação do 1o vetor.");
        return 1;
    }
    int *vetor2 = malloc(n*sizeof(int));
    if (vetor2 == NULL){
        free(vetor1);
        printf("Erro na alocação do 2o vetor.");
        return 1;
    }

    for(i = 0; i<n; i++){
        printf("%do valor: ", i+1);
        scanf("%d", &vetor1[i]);
    }

    for(i = 0; i<n; i++){
        vetor2[i] = vetor1[i];
    }

    for(i = 0; i<n; i++){
        printf("%d\t", vetor2[i]);
    }

    free(vetor1);
    free(vetor2);

    return 0;
}