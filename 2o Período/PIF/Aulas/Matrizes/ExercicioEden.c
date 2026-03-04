#include <stdio.h>

int main(void) {

    int R, C;
    scanf("%d %d", &R, &C);

    int mat[50][50];
    int soma[50];

    int i, j, entrada;
    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            scanf("%d", &entrada);
            mat[i][j] = entrada;
        }
    }

    for(i=0; i<R; i++){
        int somaLinha = 0;
        for(j=0; j<C; j++){
            somaLinha += mat[i][j];
        }
        soma[i] = somaLinha;
    }

    int indiceDoMaior = 0;
    int maiorSoma = soma[0];
    printf("\n");
    for(i=0; i<R; i++){
        printf("%d", soma[i]);
        if (soma[i] > maiorSoma){
            maiorSoma = soma[i];
            indiceDoMaior = i;
        }
        if (i < R-1){
            printf(" ");
        }
    }

    printf("\n%d", indiceDoMaior);

    return 0;
}