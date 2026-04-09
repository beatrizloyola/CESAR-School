/*

Descrição: Crie uma função cria_pessoa que:
Recebe nome e idade como parâmetros
Aloca dinamicamente uma struct Pessoa
Retorna o endereço da struct

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
};

struct Pessoa* cria_pessoa(char nome[50], int idade){
    struct Pessoa *p = malloc(sizeof(struct Pessoa));
    
    strcpy(p->nome, nome);
    p->idade = idade;
    return p;
}

int main(){
    char nome[50] = "Beatriz";
    int idade = 20;
    struct Pessoa *endereco = cria_pessoa(nome, idade);
    printf("%p", endereco);
    return 0;
}