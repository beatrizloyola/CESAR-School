/*
1) Fácil — Vetor: contar elementos maiores que a média anterior
A) Implemente uma função que receba um vetor de inteiros V e seu tamanho N como
parâmetros.
A função deve retornar quantos elementos do vetor são estritamente maiores que a média
aritmética dos elementos anteriores.
Regras:
● A posição 0 não deve ser considerada, pois não possui elementos anteriores.
● Se N < 2, retornar 0.

Exemplo:
[4, 7, 3, 10]
● 7 > média(4) → conta
● 3 > média(4,7) → não conta
● 10 > média(4,7,3) → conta
Retorno: 2

B) Implemente uma função main() que:
1. declara um vetor de tamanho N já preenchido com valores quaisquer;
2. chama a função definida acima;
3. imprime o resultado.
*/

#include <stdio.h>

int funcao(int n, int vetor[n]){
    int i, j;
    int somaAnteriores, mediaAnteriores;
    int contador = 0;
    for (i = 1; i < n; i++){
        somaAnteriores = 0;
        mediaAnteriores = 0;
        for (j = 0; j < i; j++){
            somaAnteriores += vetor[j];
        }
        mediaAnteriores = somaAnteriores / i;
        if(vetor[i] > mediaAnteriores){
            contador++;
        }
    }

    return contador;
}

int main(){
    int vetor[4] = {4,7,3,10};
    int resultado = funcao(4, vetor);
    printf("%d", resultado);
    return 0;
}