#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

typedef struct Contador{
    int trocas;
    int comparacoes;
} Contador;

Contador *bubbleSortOriginal(int vetor[], int tamanho, bool crescente, Contador *contador) {
    contador->trocas = 0;
    contador->comparacoes = 0;
    for (int i = 0; i < tamanho - 1; ++i) {

        for (int j = 0; j < tamanho - 1; ++j) {
            bool deveTrocar = false;

            if (crescente) {
                if (vetor[j] > vetor[j + 1]) {
                    deveTrocar = true;
                }
            } else {
                if (vetor[j] < vetor[j + 1]) {
                    deveTrocar = true;
                }
            }

            contador->comparacoes = contador->comparacoes + 1;

            if (deveTrocar) {
                contador->trocas = contador->trocas + 1;
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    return contador;
}

Contador *bubbleSortMelhoria1(int vetor[], int tamanho, bool crescente, Contador *contador) {
    contador->trocas = 0;
    contador->comparacoes = 0;
    for (int i = 0; i < tamanho - 1; ++i) {

        // Limite do laço reduz a cada passada (tamanho - 1 - i)
        for (int j = 0; j < tamanho - 1 - i; ++j) {
            bool deveTrocar = false;

            if (crescente) {
                if (vetor[j] > vetor[j + 1]) {
                    deveTrocar = true;
                }
            } else {
                if (vetor[j] < vetor[j + 1]) {
                    deveTrocar = true;
                }
            }

            contador->comparacoes = contador->comparacoes + 1;

            if (deveTrocar) {
                contador->trocas = contador->trocas + 1;
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
    return contador;
}

Contador *bubbleSortMelhoria2(int vetor[], int tamanho, bool crescente, Contador *contador) {
    contador->comparacoes = 0;
    contador->trocas = 0;

    // Laço 1 (Externo): Controla o número de passadas
    for (int i = 0; i < tamanho - 1; ++i) {
        bool houveTroca = false;

        // Laço 2 (Interno): Faz as comparações (1ª Melhoria: limite reduz com 'i')
        for (int j = 0; j < tamanho - 1 - i; ++j) {
            bool deveTrocar = false;

            if (crescente) {
                if (vetor[j] > vetor[j + 1]) {
                    deveTrocar = true;
                }
            } else {
                if (vetor[j] < vetor[j + 1]) {
                    deveTrocar = true;
                }
            }

            contador->comparacoes = contador->comparacoes + 1;

            if (deveTrocar) {;
                contador->trocas = contador->trocas + 1;
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                
                houveTroca = true; // Marca que houve alteração no vetor
            }
        }

        // 2ª Melhoria: Se não houve nenhuma troca nesta passada, encerra o algoritmo
        if (!houveTroca) {
            break;
        }
    }
    return contador;
}

Contador *insertionSort(int vetor[], int tamanho, bool crescente, Contador *contador){
    contador->comparacoes = 0;
    contador->trocas = 0;

    for (int i = 1; i < tamanho; i++){
        int chave = vetor[i];
        int j = i - 1;

        if (crescente == true){
            while (j >= 0 && vetor[j] > chave){
                contador->comparacoes = contador->comparacoes + 1;
                vetor[j+1] = vetor[j];
                contador->trocas = contador->trocas + 1;
                j = j - 1;
            }
        } else {
            while (j >= 0 && vetor[j] < chave){
                contador->comparacoes = contador->comparacoes + 1;
                vetor[j+1] = vetor[j];
                contador->trocas = contador->trocas + 1;
                j = j - 1;
            }
        }
        if (j >= 0) {
            contador->comparacoes = contador->comparacoes + 1;
        }
        vetor[j+1] = chave;
    }

    return contador;
}


int main() {
    int melhorCaso1[] = { 1, 2, 5, 8, 8 };
    int melhorCaso2[] = { 1, 2, 5, 8, 8 };
    int melhorCaso3[] = { 1, 2, 5, 8, 8 };
    int melhorCaso4[] = { 1, 2, 5, 8, 8 };
    int casoMedio1[] = { 5, 8, 2, 1, 8 };
    int casoMedio2[] = { 5, 8, 2, 1, 8 };
    int casoMedio3[] = { 5, 8, 2, 1, 8 };
    int casoMedio4[] = { 5, 8, 2, 1, 8 };
    int piorCaso1[] = { 8, 8, 5, 2, 1};
    int piorCaso2[] = { 8, 8, 5, 2, 1};
    int piorCaso3[] = { 8, 8, 5, 2, 1};
    int piorCaso4[] = { 8, 8, 5, 2, 1};

    Contador *contador = (Contador*)malloc(sizeof(contador));

    int n = sizeof(melhorCaso1) / sizeof(melhorCaso1[0]);

    printf("--------------------------------------------------------\n");
    printf("CENÁRIO 1: Melhor Caso (vetor já ordenado)\n");
    printf("Vetor de entrada: [ 1 2 5 8 8 ]\n");
    printf("--------------------------------------------------------\n");
    bubbleSortOriginal(melhorCaso1, n, true, contador);
    printf("[Bubble]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    bubbleSortMelhoria1(melhorCaso2, n, true, contador);
    printf("[1a Melhoria]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    bubbleSortMelhoria2(melhorCaso3, n, true, contador);
    printf("[2 Melhoria]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    insertionSort(melhorCaso4, n, true, contador);
    printf("[Insertion]  Comparações: %d | Trocas: %d\n\n", contador->comparacoes, contador->trocas);

    printf("--------------------------------------------------------\n");
    printf("CENÁRIO 2: Caso médio (ordem aleatória)\n");
    printf("Vetor de entrada: [ 5 8 2 1 8 ]\n");
    printf("--------------------------------------------------------\n");
    bubbleSortOriginal(casoMedio1, n, true, contador);
    printf("[Bubble]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    bubbleSortMelhoria1(casoMedio2, n, true, contador);
    printf("[1a Melhoria]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    bubbleSortMelhoria2(casoMedio3, n, true, contador);
    printf("[2a Melhoria]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    insertionSort(casoMedio4, n, true, contador);
    printf("[Insertion]  Comparações: %d | Trocas: %d\n\n", contador->comparacoes, contador->trocas);

    printf("--------------------------------------------------------\n");
    printf("CENÁRIO 3: Pior caso (ordem inversa)\n");
    printf("Vetor de entrada: [ 8 8 5 2 1 ]\n");
    printf("--------------------------------------------------------\n");
    bubbleSortOriginal(piorCaso1, n, true, contador);
    printf("[Bubble]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    bubbleSortMelhoria1(piorCaso2, n, true, contador);
    printf("[1a Melhoria]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    bubbleSortMelhoria2(piorCaso3, n, true, contador);
    printf("[2a Melhoria]  Comparações: %d | Trocas: %d\n", contador->comparacoes, contador->trocas);
    insertionSort(piorCaso4, n, true, contador);
    printf("[Insertion]  Comparações: %d | Trocas: %d\n\n", contador->comparacoes, contador->trocas);

    return 0;
}