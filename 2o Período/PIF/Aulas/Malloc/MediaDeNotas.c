/*

Faça um programa que aloca um vetor de floats (significando notas), com tamanho
definido pelo usuário, usando alocação dinamica.

Preencha esse vetor com dados fornecidos pelo usuário.

Calcule e exiba a média das notas da turma.

Libere a memoria alocada dinamicamente no fim do programa.

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtdNotas;
    printf("Quantas notas? ");
    scanf("%d", &qtdNotas);

    float *arr;
    arr = (float*)malloc(qtdNotas*sizeof(float));
    
    if (arr==NULL){
        printf("Erro na alocação de memória.");
        return 1;
    }

    int i;
    for (i=0; i<qtdNotas; i++){
        printf("Digite a %da nota: ", i+1);
            scanf("%f", &arr[i]);
    }

    float somaTotal = 0;
    for(i=0; i<qtdNotas; i++){
        somaTotal += arr[i];
    }

    float media = somaTotal / qtdNotas;
    printf("Média geral: %.2f", media);

    free(arr);

    return 0;
}