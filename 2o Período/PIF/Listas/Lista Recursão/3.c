/*

Q3
Implemente recursivamente a função int estaNoVetor(int v[],
int n, int x) que retorna 1 se x estiver em v e 0 caso
contrário. Não use laços.

*/

#include <stdio.h>

int estaNoVetor(int v[], int n, int x){
    if (n==0){
        return 0;
    }
    if(v[n-1] == x){
        return 1;
    } else {
        return (estaNoVetor(v, n-1, x));
    }
}

int main(){
    int vetor[5] = {1,2,3,4,5};
    int n = 5;
    int x = 2;
    int y = 0;
    printf("%d\n", estaNoVetor(vetor, n, x)); // 1
    printf("%d\n", estaNoVetor(vetor, n, y)); // 0
    return 0;
}