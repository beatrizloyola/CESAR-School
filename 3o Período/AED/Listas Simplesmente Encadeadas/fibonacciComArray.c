// Discussão: Enquanto uma lista mantêm tamanho fixo,
// uma lista simplesmente encadeada é alocada dinamicamente na memória.
// Assim, não é necessário saber previamente a quantidade de itens.

#include <stdio.h>

int main(){
    int array[10];
    int n = 5;

    array[0] = 0;

    if (n > 1){
        array[1] = 1;
        for (int i = 2; i < n; i++){
            array[i] = array[i - 1] + array[i - 2];
        }
    }

    printf("Antes da remoção:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }

    printf("\nDepois da remoção:\n");

    for (int i = 0; i < n - 1; i++){
        array[i] = array[i+1];
    }

    for (int i = 0; i < n-1; i++){
        printf("%d ", array[i]);
    }

    printf("\n");

    return 1;   
}