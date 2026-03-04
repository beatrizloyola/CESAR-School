/*
4) (Médio) Implemente uma função que receba um vetor de inteiros V e seu tamanho N e retorne o
índice do maior elemento do vetor. Em caso de empate, retornar o primeiro índice. Depois,
implemente a main() que imprime o índice encontrado.
*/

#include <stdio.h>

int maiorElemento(int n, int v[n]);

int main(){
    int vetor1[5] = {1, 2, 3, 4, 5};
    int vetor2[5] = {1, 2, 3, 5, 4};
    int vetor3[5] = {5, 4, 3, 2, 1};

    printf("%d %d %d", maiorElemento(5, vetor1), maiorElemento(5, vetor2), maiorElemento(5, vetor3));

    return 0;
}

int maiorElemento(int n, int v[n]){
    int i;
    int maior = v[0];
    int indiceMaior = 0;
    for (i = 0; i < n; i++){
        if (v[i] > maior){
            maior = v[i];
            indiceMaior = i;
        }
    }
    return indiceMaior;
}