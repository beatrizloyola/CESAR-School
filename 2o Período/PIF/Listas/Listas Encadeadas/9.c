#include <stdio.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

int maior_valor(node *head){
    if (head == NULL){
        printf("Lista vazia.\n");
        return -999999;
    }

    int maiorValor = head -> valor;

    node *percorre = head;

    while(percorre != NULL){
        if ((percorre -> valor) > maiorValor){
            maiorValor = percorre -> valor;
        }
        percorre = percorre -> next;
    }

    return maiorValor;
    
}