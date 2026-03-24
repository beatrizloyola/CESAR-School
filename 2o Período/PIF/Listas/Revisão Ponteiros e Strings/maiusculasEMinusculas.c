/*

1. O Censor do Reino — Contagem por Referência
Um escriba medieval precisava catalogar documentos secretos, contando separadamente
vogais e consoantes para calcular um índice de legibilidade. Você foi convocado para
automatizar esse processo.
Implemente a função conta_caracteres com a assinatura abaixo. Ela deve percorrer a string
usando aritmética de ponteiros (proibido usar []) e atualizar diretamente (via ponteiros) as
contagens de vogais e consoantes. Ignore qualquer caractere que não seja letra minúscula.
Estrutura:
void conta_caracteres(char *str, int *vogais, int *consoantes);
Exemplo:
para "o corvo", vogais = 2, consoantes = 3 (espaço ignorado).
Dica: percorra com while (*str != '\0') e avance com str++. 2.

*/

#include <stdio.h>

void conta_caracteres(char *str, int *vogais, int *consoantes){
    while (*str != '\0'){

        if(*str >= 'a' && *str <= 'z'){
            if(*str == 'a' || *str == 'e'|| *str == 'i' || *str == 'o' || *str == 'u'){
                *vogais += 1;
            } else{
                *consoantes += 1;
            }
        }

        str++;
    }
}

int main(){

    char frase[]= "o corvo";
    int vogais= 0;
    int consoantes = 0;
    conta_caracteres(frase, &vogais, &consoantes);
    printf("Vogais: %d\nConsoantes: %d", vogais, consoantes);

    return 0;
}