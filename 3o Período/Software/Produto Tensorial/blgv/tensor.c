#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

int lerMatriz(FILE *arquivo, Fila *fila, int *linhas, int *colunas){
    char buffer[4096];
    *linhas = 0;
    *colunas = -1;

    while (fgets(buffer, sizeof(buffer), arquivo) != NULL){
        int colunasNaLinha = 0;
        char *token = strtok(buffer, " \t\r\n");

        while (token != NULL){
            Node *novo = (Node*)malloc(sizeof(Node));
            novo->valor = atoi(token);
            enfileirar(fila, novo);
            colunasNaLinha++;
            token = strtok(NULL, " \t\r\n");
        }

        if (colunasNaLinha == 0){
            continue;
        }

        if (*colunas == -1){
            *colunas = colunasNaLinha;
        } else if (colunasNaLinha != *colunas){
            return 0;
        }

        (*linhas)++;
    }

    if (*linhas == 0 || *colunas != *linhas){
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Uso: tensor [namefile1] [namefile2]\n");
        exit(1);
    }

    FILE *arquivoMatrizA;
    arquivoMatrizA = fopen(argv[1], "r");

    if (arquivoMatrizA == NULL){
        printf("Erro ao tentar abrir o arquivo da Matriz A.");
        exit(1);
    }

    Fila *filaArquivoMatrizA;
    filaArquivoMatrizA = criarFila();

    int linhasA, tamanhoArquivoMatrizA;

    if (!lerMatriz(arquivoMatrizA, filaArquivoMatrizA, &linhasA, &tamanhoArquivoMatrizA)){
        printf("Matriz A inválida.\n");
        exit(1);
    }

    listar(filaArquivoMatrizA);

    printf("Tamanho da matriz: [%d][%d]\n", tamanhoArquivoMatrizA, tamanhoArquivoMatrizA);

    fclose(arquivoMatrizA);

    int **matrizA = (int**)malloc(tamanhoArquivoMatrizA * sizeof(int*));
    for(int i = 0; i < tamanhoArquivoMatrizA; i++){
        matrizA[i] = (int*)malloc(tamanhoArquivoMatrizA * sizeof(int));
    }

    for(int i = 0; i < tamanhoArquivoMatrizA; i++){
        for(int j = 0; j < tamanhoArquivoMatrizA; j++){
            matrizA[i][j] = filaArquivoMatrizA->head->valor;
            desenfileirar(filaArquivoMatrizA);
        }
    }

    ///

    FILE *arquivoMatrizB;
    arquivoMatrizB = fopen(argv[2], "r");

    if (arquivoMatrizB == NULL){
        printf("Erro ao tentar abrir o arquivo da Matriz B.");
        exit(1);
    }

    Fila *filaArquivoMatrizB;
    filaArquivoMatrizB = criarFila();

    int linhasB, tamanhoArquivoMatrizB;

    if (!lerMatriz(arquivoMatrizB, filaArquivoMatrizB, &linhasB, &tamanhoArquivoMatrizB)){
        printf("Matriz B inválida.\n");
        exit(1);
    }

    listar(filaArquivoMatrizB);

    printf("Tamanho da matriz: [%d][%d]\n", tamanhoArquivoMatrizB, tamanhoArquivoMatrizB);

    fclose(arquivoMatrizB);

    int **matrizB = (int**)malloc(tamanhoArquivoMatrizB * sizeof(int*));
    for(int i = 0; i < tamanhoArquivoMatrizB; i++){
        matrizB[i] = (int*)malloc(tamanhoArquivoMatrizB * sizeof(int));
    }

    for(int i = 0; i < tamanhoArquivoMatrizB; i++){
        for(int j = 0; j < tamanhoArquivoMatrizB; j++){
            matrizB[i][j] = filaArquivoMatrizB->head->valor;
            desenfileirar(filaArquivoMatrizB);
        }
    }

    ///

    int nA = tamanhoArquivoMatrizA;
    int nB = tamanhoArquivoMatrizB;

    int **resultado = (int**)malloc((nA*nB) * sizeof(int*));
    for(int i = 0; i < (nA*nB); i++){
        resultado[i] = (int*)malloc((nA*nB) * sizeof(int));
    }

    for(int i = 0; i < nA; i++){
        for(int j = 0; j < nA; j++){
            for(int k = 0; k < nB; k++){
                for(int l = 0; l < nB; l++){
                    resultado[i*nB+k][j*nB+l] = matrizA[i][j] * matrizB[k][l];
                }
            }
        }
    }

    FILE *arquivoSaida;
    arquivoSaida = fopen("tensor_blgv.out", "w");

    if (arquivoSaida == NULL){
        printf("Erro ao tentar abrir o arquivo de saída.");
        exit(1);
    }

    for(int i = 0; i < nA*nB; i++){
        for(int j = 0; j < nA*nB; j++){
            fprintf(arquivoSaida, "%d ", resultado[i][j]);
        }
        fprintf(arquivoSaida, "\n");
    }

    fclose(arquivoSaida);

    ///

    for(int i = 0; i < tamanhoArquivoMatrizA; i++){
        free(matrizA[i]);
    }
    free(matrizA);

    for(int i = 0; i < tamanhoArquivoMatrizB; i++){
        free(matrizB[i]);
    }
    free(matrizB);
    
    for(int i = 0; i < tamanhoArquivoMatrizA * tamanhoArquivoMatrizB; i++){
        free(resultado[i]);
    }
    free(resultado);
}

