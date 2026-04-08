/*

Vetor Redimensionável
Escreva uma função que receba um ponteiro para um vetor de inteiros alocado dinamicamente
e seu tamanho atual. A função deve ler novos números do usuário até que ele digite 0.
Se o vetor ficar cheio, use realloc para dobrar o tamanho dele. Não esqueça de tratar o
caso de falha no realloc.

*/

#include <stdio.h>
#include <stdlib.h>

int* funcao(int *vetor, int tamanho){
    int numero = 1;
    int contador = 0;
    while (numero != 0){
        printf("Digite um número (0 para parar): ");
        scanf("%d", &numero);
        if (contador == tamanho){
            tamanho = tamanho*2;
            int *temp = realloc(vetor, sizeof(int)*tamanho);
            if (temp == NULL){
                printf("Erro na realocação de memória\n");
                free(vetor);
                return NULL;
            }
            vetor = temp;
        }
        vetor[contador] = numero;
        contador++;
    }
    return vetor;
}

int main(){
    int *teste = malloc(sizeof(int));
    int *resultadoc = funcao(teste, 1);
}