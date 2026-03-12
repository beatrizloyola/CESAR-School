#include <stdio.h>

void swap(int *refA, int *refB){
    int temporaria = *refA;
    *refA = *refB;
    *refB = temporaria;
}

int main(){
    int a = 10;
    int b = 15;

    /*
    int *refA;
    refA = &a;
    int *refB;
    refB = &b;
    
    swap(refA, refB);
    */

    swap(&a, &b);
    printf("A: %d\nB: %d", a, b);

    return 0;
}