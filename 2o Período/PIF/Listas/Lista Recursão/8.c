/*

Q8
Usando a mesma estrutura da Q6, implemente recursivamente a função int
buscaLista(struct node *head, int x) que retorna 1 se x estiver na lista e 0 caso
contrário. Não use laços.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int valor;
    struct node *next;
} node;

int buscaLista(node *head, int x){
    if (head == NULL){
        return 0;
    }
    if (head->valor == x){
        return 1;
    } else {
        return buscaLista(head->next, x);
    }
}

int main(){
    node * head = NULL;
    head = (node *)malloc(sizeof(node));
    head -> valor = 10;

    node * no2 = NULL;
    no2 = (node *)malloc(sizeof(node));
    no2 -> valor = 20;

    node *no3 = NULL;
    no3 = (node *)malloc(sizeof(node));
    no3 ->valor = 30;
    
    head -> next = no2;
    no2 -> next = no3;
    no3 -> next = NULL;

    printf("%d\n", buscaLista(head, 15));
    printf("%d\n", buscaLista(head, 20));

    return 0;
}