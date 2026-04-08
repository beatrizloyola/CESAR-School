/*

Cópia de Strings Personalizada
Crie uma função char* clonar_string(char* s) que meça o tamanho da string s, aloque exatamente a
quantidade de memória necessária (incluindo o caractere nulo \0) e copie o conteúdo. O programa principal
deve liberar a memória após o uso.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* clonar_string(char* s){
    int tamanho = strlen(s);
    char *clone = malloc((tamanho*sizeof(char))+1);

    if (clone == NULL){
        printf("Erro na alocação de memória.\n");
        return NULL;
    }

    int i;
    for (i = 0; i < (tamanho); i++){
        clone[i] = s[i];
    }
    clone[i] = '\0';

    printf("%s", clone);
    return clone;
}

int main(){
    char *string1 = "Coisinha";
    char *resultado = clonar_string(string1);
    
    free(resultado);
    return 0;
}