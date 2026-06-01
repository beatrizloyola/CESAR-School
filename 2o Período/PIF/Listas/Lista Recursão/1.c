#include <stdio.h>

/*

Implemente recursivamente a função int somaDigitos(int n) que recebe um inteiro não
negativo e retorna a soma de seus dígitos. Não use laços.
somaDigitos(123) → 6
somaDigitos(9) → 9
somaDigitos(0) → 0

*/

int somaDigitos(int n){
    if (n <= 0){
        return 0;
    }
    if (n <= 9){
        return n;
    }

    return ((n % 10) + somaDigitos(n % 10));
}

int main(){
    int n = 123;
    printf("%d\n", somaDigitos(n));
    return 0;
}
