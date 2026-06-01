#include <stdio.h>

struct node{
    int valor;
    struct node *next;
};

int conta_nos(struct node *head){
    struct node *percorre = head;
    int contador = 0;
    while (percorre != NULL){
        contador++;
        percorre = percorre -> next;
    }
    return contador;
}