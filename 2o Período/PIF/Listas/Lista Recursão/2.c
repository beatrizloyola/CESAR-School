#include <stdio.h>

/*
Implemente recursivamente a função int contaPares(int v[], int n) que recebe um vetor
de n inteiros e retorna quantos elementos são pares. Não use laços.
*/

int contaPares(int v[], int n){
    if (n == 0){
        return n;
    }

    if(v[n-1] % 2 == 0){
        return 1 + (contaPares(v, n-1));
    } else {
        return(contaPares(v, n-1));
    }
}

int main(){
    int vetor[5] = {1,2,3,4,5};
    int n = 5;
    printf("%d\n", contaPares(vetor, n));
    return 0;
}