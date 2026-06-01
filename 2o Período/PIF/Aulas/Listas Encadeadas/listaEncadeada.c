#include <stdio.h>
#include <stdlib.h>

struct node{
    int valor;
    struct node *next;
};

void adicionar(struct node **head, int val){
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    novo -> valor = val;
    novo -> next = NULL;
    if (*head == NULL){
        *head = novo;
    } else {
        struct node *n = *head;
        while (n -> next != NULL){
            n = n -> next;
        }
        n -> next = novo;
    }
}

void remover(struct node **head){
    if (*head == NULL){
        printf("Lista vazia");
    } else if ((*head) -> next == NULL) { // Lista de um só elemento
        free(*head); // Libera o malloc
        *head = NULL; // Elemento aponta para nada (último)
    } else {
        struct node *temp, *n = *head; // Cria um n para percorrer e um temporário pra armazenar
        while (n -> next -> next != NULL){ // Enquanto o próximo do próximo não for o fim, percorre
            n = n -> next;
        }
        temp = n -> next; // Temporário é o penúltimo elemento
        n -> next = NULL; // Penúltimo elemento aponta para nada (último)
        free(temp); // Libera o malloc do temporário
    }
}

int main(){
    struct node * head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head -> valor = 1;
    head -> next = NULL;

    struct node * novo = (struct node *)malloc(sizeof(struct node));
    novo -> valor = 2;
    novo -> next = NULL;

    head -> next = novo;

}
