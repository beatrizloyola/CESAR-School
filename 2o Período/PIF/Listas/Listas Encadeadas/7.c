#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

void remove_primeiro(node **head){
    if(*head == NULL){
        printf("Lista vazia.\n");
        return;
    }

    node *temp = *head;
    *head = (*head) -> next;
    free(temp);
}