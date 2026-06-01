#include <stdio.h>

struct node{
    int valor;
    struct node *next;
};

void iniciliza_lista(struct node **head){
    (*head) -> next = NULL;
}