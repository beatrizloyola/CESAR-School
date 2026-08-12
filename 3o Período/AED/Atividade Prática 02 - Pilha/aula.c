#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
} Node;

typedef struct Pilha{
    Node *topo;
} Pilha;

Pilha *criarPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL){
        printf("Falha na alocação de memória\n");
        return NULL;
    }
    p->topo = NULL;
    return p;
}

void empilhar(Pilha *p, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL){
        printf("Falha na alocação de memória\n");
        return;
    }
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    return;
}

void desempilhar(Pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }

    Node *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
}

void consultaTopo(Pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }

    printf("%d", p->topo->valor);
    return;
}

void imprimir(Pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }

    Node *atual = p->topo;
    while (atual != NULL){
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
    return;
}