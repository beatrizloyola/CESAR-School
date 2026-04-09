/*

Crie uma struct chamada Vetor que contenha:
um ponteiro para int chamado valores
um inteiro tamanho
Depois:
Alocar dinamicamente memória para valores de acordo com tamanho.
Preencher os valores com números do usuário.
Imprimir os valores.
Liberar a memória alocada.

*/

#include <stdio.h>
#include <stdlib.h>

struct Vetor{
    int *valores;
    int tamanho;
};

int main(){
    int tamanho;
    printf("Tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *valores = malloc(sizeof(int)*tamanho);
    if (valores == NULL){
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for(int i = 0; i < tamanho; i++){
        printf("[%d] = ", i);
        scanf("%d", &valores[i]);
    }

    struct Vetor v = {valores, tamanho};

    for(int i = 0; i < v.tamanho; i++){
        printf("%d\t", v.valores[i]);
    }

    free(valores);
    return 0;
}