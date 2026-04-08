/*

Concatenação de strings com alocação dinâmica
Escreva um programa que:
• leia duas strings
• aloque dinamicamente uma terceira string com tamanho suficiente para armazenar a concatenação das duas
• copie manualmente os caracteres
• adicione o terminador '\0'
• imprima a string resultante
• libere a memória
• não usar strcat
• não usar strcpy

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string1[100];
    printf("Digite a primeira string: ");
    fgets(string1, 100, stdin);
    if (strlen(string1) > 0 && string1[strlen(string1) - 1] == '\n') {
        string1[strlen(string1) - 1] = '\0';
    }

    char string2[100];
    printf("Digite a segunda string: ");
    fgets(string2, 100, stdin);
    if (strlen(string2) > 0 && string2[strlen(string2 - 1)] == '\n'){
        string2[strlen(string2) - 1] = '\0';
    }


    char* string3 = malloc(strlen(string1) + strlen(string2) + 1);

    int i, j;

    for(i = 0; string1[i] != '\0'; i++){
        string3[i] = string1[i];
    }
    for(j = 0; string2[j] != '\0'; j++){
        string3[i+j] = string2[j];
    }
    string3[i + j] = '\0';

    printf("%s", string3);
    free(string3);
    return 0;
}