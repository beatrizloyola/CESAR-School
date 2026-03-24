/*

1. O Termômetro Científico — Estatísticas Básicas de Vetor
Uma estação meteorológica coleta temperaturas ao longo do dia e precisa calcular rapidamente a
média, o maior e o menor valor registrados. Você foi designado para implementar a função que
processa essas leituras.
Implemente a função estatisticas, que recebe um vetor de floats temp, seu tamanho n e os
endereços de três variáveis: media, maior e menor. A função deve percorrer o vetor usando
aritmética de ponteiros e atualizar as três variáveis diretamente via ponteiros. Ela não possui
retorno.
void estatisticas(float *temp, int n, float *media, float *maior, float
*menor);
Exemplo: para temp = {36.5, 38.1, 35.0, 37.4}, a função deve produzir media = 36.75,
maior = 38.1, menor = 35.0.
■ Dica: inicialize maior e menor com o primeiro elemento do vetor antes de começar o laço de comparação.

*/

void estatisticas(float *temp, int n, float *media, float *maior, float *menor){
    *maior = *temp;
    *menor = *temp;
    float total = 0;
    int i;

    for (i = 1; i < n; i++){ // Não precisa comparar o primeiro elemento com ele mesmo
        total += *temp;

        if (*temp > *maior){
            *maior = *temp;
        } else if (*temp < *menor){
            *menor = *temp;
        }

        temp++;
    }

    *media = total/n;
}