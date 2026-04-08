/*

10. Média de Alunos
Crie um programa que pergunte ao usuário quantos alunos existem na turma.
Aloque dinamicamente um vetor de float para armazenar as notas.
Após calcular a média, libere a memória.

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtdAlunos;
    printf("Quantos alunos existem na turma? ");
    scanf("%d", &qtdAlunos);

    float *notas = malloc(sizeof(float)*qtdAlunos);

    float soma = 0;

    for (int i = 0; i < qtdAlunos; i++){
        float valor;
        printf("Digite a nota do %do aluno: ", i+1);
        scanf("%f", &valor);
        soma += valor;
    }

    float media = soma/qtdAlunos;

    printf("A média geral da turma foi de %.2f.\n", media);

    free(notas);
    return 0;
}