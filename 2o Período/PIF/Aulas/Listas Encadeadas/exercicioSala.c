/*

- Defina uma estrutura para uma lista encadeada de inteiros.
- Faça uma função simples para inserir elementos no final da lista e outra para
    inserir no inicio.
- Crie um programa que preenche essa lista com dados do usuário. O usuário pode
    escolher se vai inserir no inicio ou no final, digitando as letras I ou F.
    A inserção termina quando o usuário digitar a letra T.
- Crie uma função para remover elementos duplicados da lista e chame essa função
    ao final da insercao do usuário.
- Crie uma função para imprimir a lista e chame essa função apos a remoção dos
    duplicados.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node * next;
} node;

void insereInicio(node **head, int numero){
    node *novo = (node *)malloc(sizeof(node));

    if (novo == NULL){
        printf("Erro na alocação de memória.\n");
        return;
    }
    
    novo -> valor = numero;
    novo -> next = *head;
    *head = novo;
}

void insereFinal(node **head, int numero){
    node *novo = (node *)malloc(sizeof(node));

    if (novo == NULL){
        printf("Erro na alocação de memória.\n");
        return;
    }

    novo -> valor = numero;
    novo -> next = NULL;

    if (*head == NULL){ // Lista vazia
        *head = novo;
        return;
    }

    node *percorre = *head;

    while (percorre -> next != NULL){
        percorre = percorre -> next;
    }

    percorre -> next = novo;
}

void apagaDuplicatas(node **head){
    node *percorre = *head;

    while (percorre != NULL){

        node *auxiliar = percorre;

        while (auxiliar -> next != NULL){
            if (auxiliar -> next -> valor == percorre -> valor){
                node *temp = auxiliar -> next;
                auxiliar -> next = auxiliar -> next -> next;
                free(temp);
            } else {
                auxiliar = auxiliar -> next;
            }
        }

        percorre = percorre -> next;
    }
}

void imprime(node *head){
    node *percorre = head;
    while(percorre != NULL){
        printf("%d\n", percorre -> valor);
        percorre = percorre -> next;
    }
}

int main(){
    int numero;
    char opcao = ' ';
    node *lista = NULL;

    while (1){

        scanf(" %c", &opcao);

        if (opcao == 'T'){
            break;
        }

        scanf("%d", &numero);

        if (opcao == 'I'){
            insereInicio(&lista, numero);

        } else if (opcao == 'F'){
            insereFinal(&lista, numero);

        } else {
            printf("Opção inválida.\n");
        }

    }

    apagaDuplicatas(&lista);

    printf("---------\n");
    imprime(lista);
    printf("---------\n");
    return 0;
}