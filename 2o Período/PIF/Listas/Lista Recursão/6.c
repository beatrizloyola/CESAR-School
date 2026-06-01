/*

Q6
Dada a estrutura:
struct node { int valor; struct node *next; };
Implemente recursivamente a função int tamanho(struct node *head) que retorna o
número de nós da lista. Não use laços.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

int tamanho (node *head){
    if (head == NULL){
        return 0;
    }

    return 1 + tamanho(head->next);
}

int main(){
    node * head = NULL;
    head = (node *)malloc(sizeof(node));
    head -> valor = 1;
    head -> next = NULL;

    printf("%d\n", tamanho(head));

    return 0;
}