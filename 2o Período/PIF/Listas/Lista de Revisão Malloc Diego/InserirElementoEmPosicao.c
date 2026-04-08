/*

Inserir elemento em posição específica
Escreva um programa que:

• leia um inteiro n
• aloque dinamicamente um vetor de n inteiros
• leia os elementos
• leia um valor x e uma posição p
• aumente o vetor em 1 posição usando realloc
• insira x na posição p, deslocando os elementos à direita
• imprima o vetor final
• libere a memória
Considere posições válidas de 0 até n.

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);

    int *vetor = malloc(n * sizeof(int));
    if (vetor == NULL){
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    int i;
    for (i=0; i<n; i++){
        printf("%do valor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    int x;
    printf("Valor a ser inserido: ");
    scanf("%d", &x);

    int p;
    printf("Posição: ");
    scanf("%d", &p);

    n++;
    int *temp = realloc(vetor, n * sizeof(int));
    if(temp == NULL){
        printf("Erro na realocação de memória.\n");
        free(vetor);
        return 1;
    } else {
        vetor = temp;
    }

    for(int j = n-1; j>p; j--){
        vetor[j] = vetor[j-1];
    }
    vetor[p] = x;
        

    for(i=0; i<n; i++){
        printf("%d\t", vetor[i]);
    }

    free(vetor);
    return 0;

}