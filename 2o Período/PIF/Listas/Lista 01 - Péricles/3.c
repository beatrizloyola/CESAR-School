/*
3) Médio — Vetor: remover repetições consecutivas
A) Implemente uma função que receba:
● um vetor de inteiros V,
● seu tamanho N,
● e um segundo vetor R para saída.

A função deve copiar para R apenas os elementos de V sem repetições consecutivas,
preservando a ordem, e retornar o novo tamanho de R.
Exemplo:
Entrada: [5, 5, 5, 2, 2, 7, 3, 3, 1]
Saída em R: [5, 2, 7, 3, 1]
Retorno: 5
Regras:
● Se N == 0, retornar 0.

B) Implemente uma função main() que:
1. declara um vetor original já preenchido;
2. declara um vetor de saída com tamanho suficiente;
3. chama a função;
4. imprime o vetor resultante e seu tamanho.
*/

#include <stdio.h>

int funcao(int n, int entrada[n], int saida[n]){
    if(n == 0){
        return 0;
    } else {
        int i;
        int contador = 1;
        saida[0] = entrada[0];
        
        for(i = 1; i < n; i++){
            if (entrada[i] != entrada[i - 1]){
                saida[contador] = entrada[i];
                contador++;
            }
        }

        for(i = 0; i < contador; i++){
            printf("%d ", saida[i]);
        }

        return contador;
    }
}

int main(){
    int entrada[9] = {5, 5, 5, 2, 2, 7, 3, 3, 1};
    int saida[9] = {0};
    int resultado = funcao(9, entrada, saida);
    printf("%d", resultado);

    return 0;
}