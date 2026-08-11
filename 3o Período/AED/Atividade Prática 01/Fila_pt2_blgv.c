#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int incrementaId = 1000;
int qtdMeia = 50000;
int qtdInteira = 150000;

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
} Fila;

Fila* criarFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->head = NULL;
    f->tail = NULL;
    f->tamanho = 0;
    return f;
}

void enfileirar(Fila *f, Usuario *u){
    if (f->head == NULL){
        f->head = u;
    } else {
        f->tail->prox = u;
    }
    f->tail = u;

    printf("Inserido ID %d\n", u->id);
    f->tamanho = (f->tamanho)+1;
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

Usuario* criarUsuario(){
    Usuario *u = (Usuario*)malloc(sizeof(Usuario));

    if (u == NULL){
        printf("Erro na alocação de memória");
        return NULL;
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

    strcpy(u->nome, nome);
    u->prox = NULL;
    u->id = incrementaId;
    incrementaId = incrementaId + 1;
    return u;
}

void entrarNaFila(Usuario *u, Fila *fa, Fila *naoFa){
    if (u->fa){
        enfileirar(fa, u);
        printf("Fãs na sua frente: %d\n", (fa->tamanho) - 1);
    } else {
        enfileirar(naoFa, u);
        printf("Fãs na sua frente: %d\n", (fa->tamanho));
        printf("Não-fãs na sua frente: %d\n", (naoFa->tamanho) - 1);
    }

    return;
}

void comprarInteira(Usuario *u){
    if (qtdInteira > 0){
        printf("%s comprou inteira\n", u->nome);
        qtdInteira = qtdInteira - 1;
    } else {
        printf("Inteiras esgotadas.\n");
    }
    return;
}

void comprarMeia(Usuario *u){
    if (qtdMeia > 0){
        printf("%s comprou meia\n", u->nome);
        qtdMeia = qtdMeia - 1;
    } else {
        printf("Meias esgotadas. Gostaria de comprar uma inteira?");
        printf("\n1 - Sim");
        printf("\n2 - Desistir da compra\n");
        int opcao = 0;

        while (opcao != 1 && opcao != 2){
            scanf("%d", &opcao);
        }

        if (opcao == 1){
            comprarInteira(u);
        } else if (opcao == 2) {
            printf("%s desistiu da compra.\n", u->nome);
        }
    }
    return;
}

void opcaoComprar(Usuario *u){
    printf("Vez de comprar: %s (%d)\n", u->nome, u->id);
    int opcao = -1;

    while (opcao != 1 && opcao != 0){
        printf("Opção:\n");
        printf("0 - Meia\n");
        printf("1 - Inteira\n");
        scanf("%d", &opcao);
    }

    if (opcao == 0){
        comprarMeia(u);
    } else {
        comprarInteira(u);
    }
    return;
}

void prioridadeFila(Fila *fa, Fila *naoFa){
    if (fa->head != NULL){
        printf("Fila de fãs\n");
        opcaoComprar(fa->head);
        desenfileirar(fa);
        return;
    }

    if (naoFa->head != NULL){
        printf("Fila geral\n");
        opcaoComprar(naoFa->head);
        desenfileirar(naoFa);
        return;
    }

    printf("Todas as filas estão vazias\n");
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

void opcaoMenu(Fila *fa, Fila *naoFa){
    int opcao = -1;

    while (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4){
        printf("1 - Cadastrar\n");
        printf("2 - Comprar\n");
        printf("3 - Listar\n");
        printf("4 - Encerrar\n");

        scanf("%d", &opcao);
    }

    if (opcao == 1){
        Usuario *u = criarUsuario();
        if (u != NULL){
            entrarNaFila(u, fa, naoFa);
        }
    } else if (opcao == 2) {
        prioridadeFila(fa, naoFa);
    } else if (opcao == 3) {
        listar(fa);
        listar(naoFa);
    } else {
        exit(0);
    }

    return;
}

int main(){
    Fila *fa = criarFila();
    Fila *naoFa = criarFila();

    while (true){
        opcaoMenu(fa, naoFa);
    }

    return 0;
}