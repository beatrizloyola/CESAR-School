#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Usuario {
    int id;
    char nome[50];
    bool fa;
    struct Usuario *prox;
} Usuario;

typedef struct Fila {
    Usuario *head;
    Usuario *tail;
    int tamanho;
    int inicioId;
    int qtdMeia;
    int qtdInteira;
} Fila;

Fila* criarFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->head = NULL;
    f->tail = NULL;
    f->tamanho = 0;
    f->inicioId = 1000;
    f->qtdMeia = 0;
    f->qtdInteira = 0;
    return f;
}

void enfileirar(Fila *f, Usuario *u){
    if (f->head == NULL){
        f->head = u;
    } else {
        f->tail->prox = u;
    }
    f->tail = u;
    f->tamanho = (f->tamanho)+1;
    printf("Inserido ID %d\n", u->id);
}

void desenfileirar(Fila *f){
    if (f->head == NULL){
        printf("Fila vazia\n");
        return;
    }

    Usuario *aux = f->head;

    f->head = f->head->prox;

    if(f->head == NULL){
        f->tail = NULL;
        printf("A fila esvaziou\n");
    }

    printf("%s (ID %d) saiu da fila\n", aux->nome, aux->id);
    free(aux);
    f->tamanho = f->tamanho - 1;
    return;
}

void criarUsuario(Fila *f){
    Usuario *u = (Usuario*)malloc(sizeof(Usuario));

    if (u == NULL){
        printf("Erro na alocação de memória");
        return;
    }

    printf("Nome: ");
    char nome[50];
    scanf("%s", nome);

    int fa = -1;

    while (fa != 0 && fa != 1){
        printf("Fã: ");
        scanf("%d", &fa);
        if (fa != 0 && fa != 1){
            printf("Opção inválida.\n");
        }
    }

    if (fa == 0){
        u->fa = false;
    } else {
        u->fa = true;
    }

    f->inicioId = f->inicioId + 1;
    u->id = f->inicioId;
    strcpy(u->nome, nome);
    u->prox = NULL;

    printf("Pessoas na sua frente: %d\n", f->tamanho);
    enfileirar(f, u);
    return;
}

void comprarInteira(Fila *f){
    Usuario *u = f->head;
    if (f->qtdInteira > 0){
        printf("%s comprou inteira\n", u->nome);
        f->qtdInteira = (f->qtdInteira) - 1;
        desenfileirar(f);
    } else {
        printf("Inteiras esgotadas.\n");
    }
    return;
}

void comprarMeia(Fila *f){
    if (f->qtdMeia > 0){
        printf("%s comprou meia\n", f->head->nome);
        f->qtdMeia = (f->qtdMeia) - 1;
        desenfileirar(f);
    } else {
        printf("Meias esgotadas. Gostaria de comprar uma inteira?");
        printf("\n1 - Sim");
        printf("\n2 - Desistir da compra\n");
        int opcao = 0;

        while (opcao != 1 && opcao != 2){
            scanf("%d", &opcao);
        }

        if (opcao == 1){
            comprarInteira(f);
        } else if (opcao == 2) {
            printf("%s desistiu da compra.\n", f->head->nome);
            desenfileirar(f);
        }
    }
    return;
}

void opcaoComprar(Fila *f){
    if (f->head == NULL){
        printf("Fila vazia\n");
        return;
    }

    printf("Vez de comprar: %s\n", f->head->nome);

    int opcao = -1;

    while (opcao != 1 && opcao != 0){
        printf("Opção:\n");
        printf("0 - Meia\n");
        printf("1 - Inteira\n");
        scanf("%d", &opcao);
    }

    if (opcao == 0){
        comprarMeia(f);
    } else {
        comprarInteira(f);
    }
    return;
}

void listar(Fila *f){
    Usuario *u = f->head;

    if (u == NULL){
        printf("Fila vazia\n");
        return;
    }

    printf("---\n");
    while (u != NULL){
        printf("Nome: %s | Fã: %d | ID: %d\n", u->nome, u->fa, u->id);
        u = u->prox;
    }
    printf("---\n");
    return;
}

void opcaoMenu(Fila *f){
    int opcao = -1;

    while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
        printf("1 - Cadastrar\n");
        printf("2 - Comprar\n");
        printf("3 - Listar\n");
        printf("4 - Encerrar\n");

        scanf("%d", &opcao);
    }

    if (opcao == 1){
        criarUsuario(f);
    } else if (opcao == 2) {
        opcaoComprar(f);
    } else if (opcao == 3) {
        listar(f);
    } else {
        exit(0);
    }

    return;
}

int main(){
    Fila *fila = criarFila();
    fila->qtdInteira = 150000;
    fila->qtdMeia = 50000;

    while (true){
        opcaoMenu(fila);
    }

    return 0;
}