#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

void remove_ultimo(struct node **head){
    if (*head == NULL){
        printf("Lista vazia.\n");
        return;
    }

    if ((*head) -> next == NULL){
        printf("Lista de só um elemento.\n");
        free(*head);
        (*head) = NULL;
        return;
    }

    node *percorre = *head;
    while (percorre -> next -> next != NULL){
        percorre = percorre -> next;
    }

    node *temp = percorre -> next;

    percorre -> next =  NULL;

    free(temp);
}