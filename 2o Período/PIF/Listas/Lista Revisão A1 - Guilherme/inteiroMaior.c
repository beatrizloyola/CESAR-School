/*
Implemente uma função maior() que receba dois inteiros e retorne o maior deles.
Na main, leia os valores e mostre o maior.
*/

#include <stdio.h>

int maior(int a, int b){
    if(a > b){
        return a;
    } else if (b > a) {
        return b;
    } else {
        return 0;
    }
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", maior(a,b));
}