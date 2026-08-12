#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Como eu salvo uma matriz de tamanho que eu não conheço ainda?
    // Cada elemento do texto deve ser lido isoladamente, ignorando espaços
    // Se estiver na mesma linha do texto, deve estar na mesma linha da matriz
        // Acabou a linha, passa para a próxima

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

typedef struct Fila {
    Node *head;
    Node *tail;
    int tamanho;
} Fila;

Fila* criarFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->head = NULL;
    f->tail = NULL;
    f->tamanho = 0;
    return f;
}

void enfileirar(Fila *f, Node *n){
    n->prox = NULL;
    if (f->head == NULL){
        f->head = n;
    } else {
        f->tail->prox = n;
    }
    f->tail = n;
    f->tamanho = (f->tamanho)+1;
    return;
}

void desenfileirar(Fila *f){
    if (f->head == NULL){
        printf("Fila vazia\n");
        return;
    }

    Node *aux = f->head;

    f->head = f->head->prox;

    if(f->head == NULL){
        f->tail = NULL;
        printf("A fila esvaziou\n");
    }

    free(aux);
    f->tamanho = f->tamanho - 1;
    return;
}

void listar(Fila *f){
    Node *n = f->head;

    if (n == NULL){
        printf("Fila vazia\n");
        return;
    }

    while (n != NULL){
        printf("%d\n", n->valor);
        n = n->prox;
    }
    return;
}

int getTamanhoMatriz(Fila *f){
    double tamanho = sqrt(f->tamanho);
    int tamanhoInteiro = (int)tamanho;
    return tamanhoInteiro;
}

int main(){
    FILE *arquivoMatrizA;
    arquivoMatrizA = fopen("matriz_A.txt", "r");

    if (arquivoMatrizA == NULL){
        printf("Erro ao tentar abrir o arquivo.");
        exit(1);
    }

    Fila *filaArquivoMatrizA;
    filaArquivoMatrizA = criarFila();

    int numA;

    while (fscanf(arquivoMatrizA, "%d", &numA) != EOF){
        Node *novo = (Node*)malloc(sizeof(Node));
        novo->valor = numA;
        enfileirar(filaArquivoMatrizA, novo);
    }

    listar(filaArquivoMatrizA);

    int tamanhoarquivoMatrizA = getTamanhoMatriz(filaArquivoMatrizA);

    printf("Tamanho da matriz: [%d][%d]\n", tamanhoarquivoMatrizA, tamanhoarquivoMatrizA);

    fclose(arquivoMatrizA);

    int matrizA[tamanhoarquivoMatrizA][tamanhoarquivoMatrizA];

    while (filaArquivoMatrizA->head != NULL){
        for(int i = 0; i < tamanhoarquivoMatrizA; i++){
            for(int j = 0; i < tamanhoarquivoMatrizA; j++){
                matrizA[i][j] = filaArquivoMatrizA->head->valor;
                desenfileirar(filaArquivoMatrizA);
            }
        }
    }

    ///

    FILE *arquivoMatrizB;
    arquivoMatrizB = fopen("matriz_B.txt", "r");

    if (arquivoMatrizB == NULL){
        printf("Erro ao tentar abrir o arquivo.");
        exit(1);
    }

    Fila *filaArquivoMatrizB;
    filaArquivoMatrizB = criarFila();

    int numB;

    while (fscanf(arquivoMatrizB, "%d", &numB) != EOF){
        Node *novo = (Node*)malloc(sizeof(Node));
        novo->valor = numB;
        enfileirar(filaArquivoMatrizB, novo);
    }

    listar(filaArquivoMatrizB);

    int tamanhoArquivoMatrizB = getTamanhoMatriz(filaArquivoMatrizB);

    printf("Tamanho da matriz: [%d][%d]", tamanhoArquivoMatrizB, tamanhoArquivoMatrizB);

    fclose(arquivoMatrizB);

    int matrizB[tamanhoArquivoMatrizB][tamanhoArquivoMatrizB];

    while (filaArquivoMatrizB->head != NULL){
        for(int i = 0; i < tamanhoArquivoMatrizB; i++){
            for(int j = 0; i < tamanhoArquivoMatrizB; j++){
                matrizA[i][j] = filaArquivoMatrizB->head->valor;
                desenfileirar(filaArquivoMatrizB);
            }
        }
    }
}