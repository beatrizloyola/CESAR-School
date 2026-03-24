/*

3. O Arquivista das Runas — Medidor de Comprimento
Em um arquivo antigo, cada pergaminho é armazenado como uma sequência de símbolos
terminada por uma marca especial de fim. Antes de catalogar os textos, é necessário
descobrir quantos caracteres cada pergaminho possui, sem usar ferramentas prontas do
reino.
Escreva um programa em C que leia uma string fornecida pelo usuário com até 100
caracteres. Implemente uma função que receba uma string e retorne o seu comprimento,
ou seja, a quantidade de caracteres até o caractere nulo ('\0'), sem utilizar funções da
biblioteca padrão, como strlen. O cálculo deve ser feito exclusivamente utilizando aritmética
de ponteiros.
Estrutura:
int comprimento(char *str);
Exemplo de Entrada:
programacao
Exemplo de Saída:
Comprimento da string: 11
Dica: percorra a string caractere por caractere até encontrar '\0'.

*/

#include <stdio.h>

int comprimentoComInput(char *str){
    int contador = 0;
    while (*str != '\0'){
        if (*str != '\n'){
            contador++;
        }
        str++;
    }

    return contador;
}

int comprimentoSemInput(char *str){
    int contador = 0;
    while (*str != '\0'){
            contador++;
        str++;
    }
    return contador;
}

int main(){
    char str[100] = "programacao";
    // fgets(str, 100, stdin);
    
    printf("%d", comprimentoSemInput(str));

    return 0;
}

