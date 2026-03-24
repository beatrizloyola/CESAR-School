/*

3. A Fábrica de Peças — Busca e Substituição em Vetor
Uma fábrica registra o peso de peças produzidas em um vetor de floats. Peças fora do intervalo de
tolerância precisam ser substituídas por um valor padrão de retrabalho para sinalizar ao operador.
Sua função deve realizar essa substituição diretamente no vetor original.
Implemente substitui_fora_do_intervalo, que recebe o vetor pesos, seu tamanho n, os
limites minimo e maximo (floats) e o valor substituto (float). A função deve percorrer o vetor
com aritmética de ponteiros, substituindo in-place todo elemento que esteja fora do intervalo
[minimo, maximo]. Deve retornar quantas substituições foram feitas.
int substitui_fora_do_intervalo(float *pesos, int n, float minimo, float
maximo, float substituto);
Exemplo: pesos = {1.2, 0.5, 3.8, 2.1, 4.5}, minimo = 1.0, maximo = 3.0, substituto = -1.0
→ vetor vira {1.2, -1.0, -1.0, 2.1, -1.0}, retorno = 3.

■ Restrição: proibido usar o operador []. Toda leitura e escrita deve ser feita via aritmética de
ponteiros.

*/

int substitui_fora_do_intervalo(float *pesos, int n, float minimo, float
maximo, float substituto){
    int substituidos = 0;
    int i;
    for (i = 0; i < n; i++){
        if (*pesos < minimo || *pesos > maximo){
            *pesos = substituto;
            substituidos++;
        }
        pesos++;
    }
    return substituidos;
}