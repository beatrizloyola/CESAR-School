#include <stdio.h>

void multiplica(int primeira[3][3], int segunda[3][3], int terceira[3][3]);
void printMatriz(int n, int matriz[n][n]);

int main(){
    int matriz1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matriz2[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    int matriz3[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    multiplica(matriz1, matriz2, matriz3);
    printMatriz(3, matriz3);

}

void multiplica(int primeira[3][3], int segunda[3][3], int terceira[3][3]){
    int i, j, k;
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            terceira[i][j] =0 ;
            for (k = 0; k < 3; k++) {
                terceira[i][j] += primeira[i][k] * segunda[k][j];
            }
        }
    }
}

void printMatriz(int n, int matriz[n][n]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}