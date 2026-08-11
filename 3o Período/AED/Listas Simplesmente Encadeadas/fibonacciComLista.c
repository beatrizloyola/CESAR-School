// Discussão: Enquanto uma lista mantém tamanho fixo,
// uma lista simplesmente encadeada é alocada dinamicamente na memória.
// Assim, não é necessário saber previamente a quantidade de itens.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;


int fib(int n){
    if (n <= 1){
        return n;
    }
    return (fib(n-1) + fib(n-2));
}

void adicionar(Node **head, int val){
    Node *novo = (Node *)malloc(sizeof(Node));
    novo -> valor = val;
    novo -> next = NULL;
    if (*head == NULL){
        *head = novo;
    } else {
        Node *n = *head;
        while (n -> next != NULL){
            n = n -> next;
        }
        n -> next = novo;
    }
}

void imprimir(Node *head){
    Node *percorre = head;
    while(percorre != NULL){
        printf("%d ", percorre -> valor);
        percorre = percorre -> next;
    }
}

void remove_primeiro(Node **head){
    if (*head == NULL){
        printf("Lista vazia");
        return;
    }

    Node *atual = *head;
    *head = atual->next;
    free(atual);
}

int main(){
    int n = 5;
    Node *array = NULL;

    if (n > 1){
        for (int i = 0; i < n; i++){
            adicionar(&array, fib(i));
        }
    }

    printf("Antes da remoção:\n");

    imprimir(array);

    printf("\nDepois da remoção:\n");

    remove_primeiro(&array);

    imprimir(array);

    printf("\n");

    return(0);
}