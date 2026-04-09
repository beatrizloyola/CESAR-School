/*

Implemente um programa em C que defina uma struct chamada Pessoa, contendo os campos nome e 
idade. Crie uma função que receba o nome, a idade e o endereço de uma variável do tipo Pessoa,
preencha essa estrutura com os valores informados e retorne o ponteiro para ela. No programa
principal, crie uma pessoa, chame a função para inicializá-la e exiba na tela o endereço
retornado pela função e o endereço da variável original para verificar se ambos são iguais.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    char nome[50];
    int idade;
};

struct Pessoa* criaPessoa(char nome[50], int idade, struct Pessoa *p){
    strcpy(p->nome, nome);
    p->idade = idade;
    return p;
}

int main(){
    char nome[50] = "Beatriz";
    int idade = 20;
    struct Pessoa *p1 = malloc(sizeof(struct Pessoa));

    printf("Original: %p", p1);
    struct Pessoa *p2 = criaPessoa(nome, idade, p1);
    printf("Função: %p", p2);

    free(p1);
    return 0;
}