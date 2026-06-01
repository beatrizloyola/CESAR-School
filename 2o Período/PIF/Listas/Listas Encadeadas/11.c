#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

void remove_valor(struct node **head, int valor){
    if (*head == NULL){
        printf("Lista vazia.\n");
        return;
    }

    node *percorre = *head;
    node *anterior = NULL;

    while(percorre != NULL){
        if (percorre -> valor == valor){
            if (anterior == NULL){
                *head = percorre->next;
            } else {
                anterior-> next = percorre -> next;
            }

            free(percorre);
            return;
        }

        anterior = percorre;
        percorre = percorre -> next;
    }

    printf("Valor não encontrado.\n");
    return;
}