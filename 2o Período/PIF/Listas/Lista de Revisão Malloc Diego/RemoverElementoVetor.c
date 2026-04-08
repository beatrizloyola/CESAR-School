/*

Remover um elemento de um vetor
Escreva um programa que:
• leia um inteiro n
• aloque dinamicamente um vetor de n inteiros
• leia os valores do vetor
• leia um valor x a ser removido
• remova a primeira ocorrência de x
• reduza o vetor com realloc
• imprima o vetor resultante
Observação:
• caso x não exista, o vetor deve permanecer inalterado

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanhoVetor;
    printf("Tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    int *vetor = malloc(sizeof(int)*tamanhoVetor);
    if (vetor == NULL){
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    int i;
    for(i=0; i<tamanhoVetor; i++){
        int valor;
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    int removido;
    printf("Digite o valor a ser removido: ");
    scanf("%d", &removido);

    for(i=0; i<tamanhoVetor; i++){
        if (vetor[i] == removido){
            tamanhoVetor--;

            for(int j = i; j < tamanhoVetor; j++){
                vetor[j] = vetor[j+1];
            }

            int *temp = realloc(vetor, tamanhoVetor * sizeof(int));
            if (temp == NULL){
                free(vetor);
                printf("Erro na realocação de memória.\n");
                return 1;
            } else {
                vetor = temp;
            }

            printf("Valor removido.\n");

            for(int k=0; k<tamanhoVetor; k++){
                printf("%d\t", vetor[k]);
            }

            free(vetor);

            return 0;
        }
    }

    printf("Valor não encontrado no vetor.");
    free(vetor);
    return 0;
}