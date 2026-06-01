#include <stdio.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

void adiciona_final(struct node **head, int valor){
    
    node *novo = (node *)malloc(sizeof(node));

    if (novo == NULL){
        printf("Erro na alocação de memória\n");
        return;
    }

    novo -> next = NULL;
    novo -> valor = valor;

    if (*head == NULL){
        *head = novo;
        return;
    }

    node *percorre = *head;

    while (percorre -> next != NULL){
        percorre = percorre -> next;
    }

    percorre -> next = novo;
}

