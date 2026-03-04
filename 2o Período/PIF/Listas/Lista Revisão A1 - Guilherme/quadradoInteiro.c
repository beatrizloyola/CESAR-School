/*
Escreva uma função quadrado() que receba um número inteiro
e retorne seu quadrado. Na main, leia um número e exiba o resultado.
*/

#include <stdio.h>

int quadrado(int numero){
    return numero*numero;
}

int main(){
    int numero;
    scanf("%d", &numero);
    printf("%d", quadrado(numero));
    return 0;
}