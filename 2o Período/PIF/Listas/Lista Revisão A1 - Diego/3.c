/*
3) (Médio) Implemente uma função que receba um inteiro N e uma matriz N x N e retorne a soma
dos elementos acima da diagonal principal. Em seguida, implemente a main() que testa a função.
*/

#include <stdio.h>

int somaAcimaPrincipal(int n, int matriz[n][n]);

int main(){

    int matriz[4][4] = {{0,1,2,3}, {4,5,6,7}, {8,9,10,11}, {12,13,14,15}};
    int eita = somaAcimaPrincipal(4, matriz);
    printf("%d", eita);

    return 0;
}

int somaAcimaPrincipal(int n, int matriz[n][n]){
    int i, j;
    int resultado = 0;
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (j > i){
                resultado += matriz[i][j];
            }
        }   
    }
    return resultado;
}