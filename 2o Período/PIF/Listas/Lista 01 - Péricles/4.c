/*
4) Médio/Difícil — Matriz: linha com mais mudanças de sinal
A) Implemente uma função que receba um inteiro N e uma matriz quadrada N x N de inteiros.
A função deve retornar o índice da linha que possui a maior quantidade de mudanças de
sinal entre elementos consecutivos.
Considere que há mudança de sinal entre dois elementos consecutivos a e b quando:
● um é positivo e o outro é negativo.

Regras:
● O valor 0 não conta como positivo nem negativo, então qualquer comparação
envolvendo zero não gera mudança de sinal.
● Em caso de empate, retornar o índice da primeira linha encontrada.

● Considere N > 0.

Exemplo de linha:
[4, -2, -7, 3, 0, -1]
Mudanças de sinal:
● 4 -> -2 → sim
● -2 -> -7 → não
● -7 -> 3 → sim
● 3 -> 0 → não
● 0 -> -1 → não
Total: 2

B) Implemente uma função main() que:
1. define uma matriz já preenchida;
2. chama a função;
3. imprime o índice retornado.
*/

#include <stdio.h>

int funcao(int n, int matriz[n][n]){
    int i, j;
    int maiorQtdDiferencas = 0;
    int indiceMaiorQtdDiferencas = 0;
    for(i = 0; i < n; i++){
        int qtdDiferencasAtual = 0;
        int sinalAtual;
        int sinalAnterior = 0;
        for(j = 0; j < n; j++){
            if (matriz[i][j] > 0){
                sinalAtual = 1;
            } else if (matriz[i][j] < 0){
                sinalAtual = -1;
            } else {
                sinalAtual = 0;
            }

            if (sinalAtual != 0 && sinalAnterior != 0 && sinalAnterior != sinalAtual){
                qtdDiferencasAtual++;
            }

            if (qtdDiferencasAtual > maiorQtdDiferencas){
                maiorQtdDiferencas = qtdDiferencasAtual;
                indiceMaiorQtdDiferencas = i;
            }

            sinalAnterior = sinalAtual;
        }
    }
    return indiceMaiorQtdDiferencas;
}

int main(){
    int matriz[3][3] = {{4, 0, 0}, {0, 0, -1}, {1, 0, 1}};
    int resultado = funcao(3, matriz);
    printf("%d", resultado);

    return 0;
}