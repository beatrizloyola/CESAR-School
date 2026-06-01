#include <stdio.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

node* busca(node *head, int valor){
    node *percorre = head;
    while(percorre != NULL){
        if (percorre -> valor == valor){
            return percorre;
        }
        percorre = percorre -> next;
    }
    return NULL;
}