/*

5. O Minerador de Dados — Filtro Numérico
Uma empresa recebeu logs de sensores industriais cheios de ruído: os registros misturam
letras, símbolos e os valores numéricos que realmente importam. Sua missão é construir o
filtro que extrai apenas os dígitos.
Implemente extrai_digitos, que percorre *origem exclusivamente com aritmética de
ponteiros (o operador [] é proibido) e copia somente os caracteres de '0' a '9' para
*destino, corretamente terminado com '\0'. Retorne a quantidade de dígitos copiados.
Estrutura:
int extrai_digitos(char *origem, char *destino);
Exemplo:
extrai_digitos("T3mp:42C #7!", dest) → dest = "3427", retorno = 4.
Dica: use dois ponteiros — um para leitura e outro para escrita — avançando cada
um independentemente.

*/

#include <stdio.h>

int extrai_digitos(char *origem, char *destino){
    int contador = 0;
    while (*origem != '\0'){
        if (*origem >= '0' && *origem <= '9'){
            *destino = *origem;
            destino++;
            contador++;
        }
        origem++;
    }

    return contador;
}

int main(){
    char frase[] = "T3mp:42C #7!";
    char destino[100];

    printf("%d\n", extrai_digitos(frase, destino));
    printf("%s\n", destino);

    return 0;

}