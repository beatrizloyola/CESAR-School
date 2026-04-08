/*

Aumentar o tamanho de um vetor com realloc
Escreva um programa que:
• aloque inicialmente um vetor para 5 inteiros
• leia 5 valores
• use realloc para aumentar o vetor para 10 posições
• leia os 5 novos valores
• imprima todos os 10 elementos
• libere a memória

*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vetor = malloc(5 * sizeof(int));
    if (vetor == NULL){
        return 1;
    }

    int i;
    for(i=0; i<5; i++){
        int valor;
        printf("%do valor: ", i+1);
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    int *temp = realloc(vetor, 10*sizeof(int));
    if (temp == NULL){
        free(vetor);
        return 1;
    }
    vetor = temp;

    for(i=5; i<10; i++){
        int valor;
        printf("%do valor: ", i+1);
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    for(i=0; i<10; i++){
        printf("%d\t", vetor[i]);
    }

    free(vetor);
    return 0;
}