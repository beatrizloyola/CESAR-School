#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
} Node;

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

void remover(Node **head, int i){
    Node *atual = *head;
    Node *anterior = NULL;

    while (atual != NULL){
        if (atual->valor == i){
            if (anterior == NULL){
                *head = atual -> next;
            } else {
                anterior->next = atual->next;
            }

            free(atual);
            return;
        }
        anterior = atual;
        atual = atual -> next;
    }
}

void imprimir(Node *head){
    Node *percorre = head;
    while(percorre != NULL){
        printf("%d ", percorre -> valor);
        percorre = percorre -> next;
    }
}

int main(){
    Node *array = NULL;
    int n = 10;
    if (n > 1){
        for (int i = 0; i < n; i++){
            adicionar(&array, i);
        }
    }

    printf("Antes da remoção:\n");

    imprimir(array);

    printf("\nDepois da remoção:\n");

    remover(&array, 4);

    imprimir(array);

    printf("\n");

    return(0);
    return 1;
}