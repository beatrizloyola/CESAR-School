/*

Q7
Usando a mesma estrutura da Q6, implemente recursivamente a função int somaLista(struct
node *head) que retorna a soma de todos os valores da lista. Não use laços.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

int somaLista(node *head){
    if (head == NULL){
        return 0;
    }

    return head->valor + somaLista(head->next);
}

int main(){
    node * head = NULL;
    head = (node *)malloc(sizeof(node));
    head -> valor = 10;

    node * no2 = NULL;
    no2 = (node *)malloc(sizeof(node));
    no2 -> valor = 20;
    
    head -> next = no2;
    no2 -> next = NULL;

    printf("%d\n", somaLista(head));

    return 0;
}