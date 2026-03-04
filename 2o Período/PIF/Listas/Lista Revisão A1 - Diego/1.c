/*
1) (Fácil) Implemente uma função que receba um vetor de inteiros V e seu tamanho N e retorne a
quantidade de elementos pares no vetor. Se N == 0, retornar 0. Em seguida, implemente a main()
que declara o vetor, chama a função e imprime o resultado.
*/

#include <stdio.h>

int paresNoVetor(int tamanhoVetor, int vetor[tamanhoVetor]);

int main(){
    int vetor[2] = {9, 2};
    int tamanhoVetor = 2;
    int resultado = paresNoVetor(vetor, tamanhoVetor);
    printf("%d", resultado);

    return 0;
}

int paresNoVetor(int vetor[], int tamanhoVetor){
    int contadorPares = 0;
    int i;
    for(i = 0; i < tamanhoVetor; i++){
        if (vetor[i] % 2 == 0){
            contadorPares += 1;
        }
    }
    return contadorPares;
}