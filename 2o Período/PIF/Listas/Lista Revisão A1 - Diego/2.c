/*
2) (Fácil) Implemente uma função que receba uma matriz quadrada N x N e retorne 1 se ela for
uma matriz identidade e 0 caso contrário. Em seguida, implemente a main() que define a matriz e
imprime o resultado.
*/

#include <stdio.h>

int checaIdentidade(int n, int matriz[n][n]);

int main(){
    int matrizIdentidade[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    int matrizNaoIdentidade[3][3] = {{1, 0, 0}, {1, 1, 0}, {0, 0, 1}};
    printf("%d\n", checaIdentidade(3, matrizIdentidade));
    printf("%d\n", checaIdentidade(3, matrizNaoIdentidade));

    return 0;
}

int checaIdentidade(int n, int matriz[n][n]){
    int i, j;
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if (i == j){
                if(matriz[i][j] == 1){
                    printf("[%d][%d] = %d: Até aqui tudo bem\n", i, j, matriz[i][j]);
                } else {
                    printf("[%d][%d] = %d: It's over\n", i, j, matriz[i][j]);
                    return 0;
                }
            } else {
                if (matriz[i][j] == 0){
                    printf("[%d][%d] = %d: Até aqui tudo bem\n", i, j, matriz[i][j]);
                } else {
                    printf("[%d][%d] = %d: It's over\n", i, j, matriz[i][j]);
                    return 0;
                }
            }
        }
    }
    return 1;
}