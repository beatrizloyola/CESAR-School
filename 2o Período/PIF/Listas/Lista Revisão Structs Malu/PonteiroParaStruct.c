/*

Crie uma struct chamada Pessoa com:
nome (string de até 50 caracteres)
idade (int)
Depois:
Declare um ponteiro para Pessoa.
Alocar memória dinamicamente para ele.
Preencher os campos e imprimir.

*/

#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
    char nome[50];
    int idade;
};

int main(){
    struct Pessoa *ponteiro = malloc(sizeof(char)*50 + sizeof(int));
    printf("Nome: ");
    scanf("%s", ponteiro->nome);
    printf("Idade: ");
    scanf("%d", &ponteiro->idade);
    printf("%s, %d anos", ponteiro->nome, ponteiro->idade);
    return 0;
}