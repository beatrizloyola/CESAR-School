/*

Cadastro de Aluno com Média
Defina uma struct chamada Aluno contendo:
● char nome[50]
● float nota1
● float nota2
● float nota3
Implemente uma função chamada calcular_media_aluno. A função deve receber como
parâmetro:
● uma struct do tipo Aluno

A função deve retornar a média aritmética das três notas do aluno.

*/

#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
};

float calcular_media_aluno(struct Aluno a){
    float media = (a.nota1 + a.nota2 + a.nota3) / 3;
    return media;
}

/*

Implemente uma função chamada buscar_melhor_aluno. A função deve receber como
parâmetros:
● um vetor de structs do tipo Aluno
● um inteiro n
A função deve retornar o índice do aluno com maior média. Em caso de empate, retorne o
primeiro encontrado.

*/

int buscar_melhor_aluno(struct Aluno v[], int n){
    int indice = 0;
    float melhor_media = calcular_media_aluno(v[0]);
    for(int i = 1; i < n; i++){
        float media = calcular_media_aluno(v[i]);
        if (media > melhor_media){
            indice = i;
            melhor_media = media;
        }
    }
    return indice;
}

/*

Implemente uma função main() que:
1. leia um inteiro n;
2. declare um vetor de Aluno com n posições;
3. leia o nome e as três notas de cada aluno;
4. chame buscar_melhor_aluno;
5. imprima o nome e a média do aluno encontrado.

*/

int main(){
    int n;
    printf("n: ");
    scanf("%d", &n);

    struct Aluno vetor[n];

    for(int i=0; i<n; i++){
        printf("\n%do aluno\n", i+1);
        printf("Nome: ");
        scanf("%s", &vetor[i].nome);
        printf("Nota 1: ");
        scanf("%f", &vetor[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &vetor[i].nota2);
        printf("Nota 3: ");
        scanf("%f", &vetor[i].nota3);
    }

    int melhor = buscar_melhor_aluno(vetor, n);
    printf("Melhor aluno: %s\nMédia: %.2f\n", vetor[melhor].nome, calcular_media_aluno(vetor[melhor]));

    return 0;
}

