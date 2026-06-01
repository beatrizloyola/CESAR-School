#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

void inverte_lista(struct node **head){
    if (*head == NULL){
        printf("Lista vazia.\n");
        return;
    }

    node *atual = *head;
    node *anterior = NULL;
    node *proximo = (*head) -> next;

    while(atual != NULL){
        proximo = atual-> next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }
    *head = anterior;
}