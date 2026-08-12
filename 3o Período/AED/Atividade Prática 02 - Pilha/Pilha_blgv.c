/*

Uso de LLM (Claude Code): Rodar testes automatizados e procurar edge cases
Meu slop é humano!!

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int modId = 1000;

typedef struct Acao{
    int id;
    char tipo[10];
    char conteudo[100];
    struct Acao *prox;
} Acao;

typedef struct Pilha {
    Acao *topo;
    int tamanho;
    int tamanhoMax;
} Pilha;

Pilha *criarPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL){
        printf("Falha na alocação de memória\n");
        exit(1);
    }
    p->topo = NULL;
    p->tamanho = 0;
    p->tamanhoMax = 20;
    return p;
}

Acao *criarAcao(){
    Acao *a = (Acao*)malloc(sizeof(Acao));
    if (a == NULL){
        printf("Falha na alocação de memória\n");
        return NULL;
    }

    char tipo[10] = "";
    while (strcmp(tipo, "Digitar") && strcmp(tipo, "Apagar") && strcmp(tipo, "Colar") && strcmp(tipo, "Formatar")){
        printf("Ação (Digitar, Apagar, Colar, Formatar): ");
        scanf("%s", tipo);
    }
    strcpy(a->tipo, tipo);

    char conteudo[100] = "";
    while (!strcmp(conteudo, "")){
        printf("Conteúdo: ");
        scanf("%s", conteudo);
    }
    strcpy(a->conteudo, conteudo);
    
    modId = modId + 1;
    a->id = modId;

    return a;
}

int acoesRestantes(Pilha *p){
    int qtdRestantes = (p->tamanhoMax) - (p->tamanho);
    return qtdRestantes;
}

void empilhar(Pilha *p, Acao *a){
    if (a == NULL){
        printf("Falha na alocação de memória\n");
        return;
    }

    if (acoesRestantes(p) <= 0){
        printf("Número máximo de ações atingido.\n");
        return;
    }

    a->prox = p->topo;
    p->topo = a;
    p->tamanho = p->tamanho + 1;
    return;
}

void desempilhar(Pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }

    Acao *aux = p->topo;
    p->topo = p->topo->prox;
    p->tamanho = p->tamanho - 1;

    printf("Ação removida:\n");
    printf("Tipo: %s | Conteúdo: %s\n", aux->tipo, aux->conteudo);
    
    printf("Ações restantes: %d\n", acoesRestantes(p));

    free(aux);
    return;
}

void consultaTopo(Pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }

    printf("Última Ação: \n");
    printf("Tipo: %s | Conteúdo: %s\n", p->topo->tipo, p->topo->conteudo);
    return;
}

void imprimir(Pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }

    Acao *atual = p->topo;
    while (atual != NULL){
        printf("Tipo: %s | Conteúdo: %s\n", atual->tipo, atual->conteudo);
        atual = atual->prox;
    }
    return;
}

void opcaoMenu(Pilha *p){
    printf("Editor de texto\n");
    printf("---------------\n");
    printf("1 - Nova ação\n");
    printf("2 - Visualizar última ação\n");
    printf("3 - Desfazer última ação\n");
    printf("4 - Visualizar histórico\n");
    printf("5 - Sair\n");

    int opcao = -1;

    while (opcao != 1 && opcao != 2 && opcao != 3 && opcao !=4 && opcao != 5){
        if (scanf("%d", &opcao) != 1){
            while (getchar() != '\n');
            opcao = -1;
        }
    }

    if (opcao == 1){
        Acao *a = criarAcao();
        empilhar(p, a);
    } else if (opcao == 2){
        consultaTopo(p);
    } else if (opcao == 3){
        desempilhar(p);
    } else if (opcao == 4){
        imprimir(p);
    } else if (opcao == 5){
        exit(0);
    }
}

int main(){
    Pilha *p = criarPilha();
    while(1){
        opcaoMenu(p);
    }
    return 0;
}