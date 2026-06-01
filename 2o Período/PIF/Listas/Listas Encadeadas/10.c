#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

void libera_lista(struct node **head){
    node *atual;
    node *proximo;
    while((*head) != NULL){
        atual = (*head);
        proximo = (*head) -> next;
        free(atual);
        *head = proximo;
    }
}