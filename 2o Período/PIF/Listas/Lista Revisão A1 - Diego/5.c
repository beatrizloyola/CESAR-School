/*
5) (Difícil) Implemente uma função que receba duas matrizes A e B de ordem N x N e retorne 1 se
B for a transposta de A e 0 caso contrário. Implemente também a main() para testar.
*/

#include <stdio.h>

int transposta(int n, int a[n][n], int b[n][n]);

int main(){
    int matriz1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriz2[3][3] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    printf("%d", transposta(3, matriz1, matriz2));
}

int transposta(int n, int a[n][n], int b[n][n]){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(a[i][j] == b[j][i]){
                printf("Até aqui tudo bem...\n");
            } else {
                return 0;
            }
        }
    }
    printf("Deu tudo certo, família!");
    return 1;
}