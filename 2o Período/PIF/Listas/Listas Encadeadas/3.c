#include <stdio.h>

typedef struct node{
    int valor;
    struct node *next;
}node;

void exibe_lista(node *head){
    node *percorre = head;
    while (percorre != NULL){
        printf("%d ", percorre -> valor);
        percorre = percorre -> next;
    }
}