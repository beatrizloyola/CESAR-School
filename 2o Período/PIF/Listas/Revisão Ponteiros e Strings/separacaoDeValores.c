/*

2. O Cofre do Banco — Separação de Valores
Um sistema bancário precisa separar, de uma lista de transações, os valores positivos (depósitos)
dos negativos (saques) para gerar relatórios distintos. Sua função receberá o vetor original e
deverá preencher dois vetores de saída.
Escreva a função separa_transacoes, que recebe o vetor valores de floats com n elementos,
um vetor positivos, um vetor negativos e dois ponteiros inteiros qtd_pos e qtd_neg. A
função deve percorrer o vetor com aritmética de ponteiros, copiar cada elemento para o vetor
correto e atualizar as contagens via ponteiro. O valor 0.0 deve ser ignorado.
void separa_transacoes(float *valores, int n, float *positivos, int *qtd_pos,
float *negativos, int *qtd_neg);
Exemplo: para {120.0, -45.5, 0.0, 300.0, -80.0}, positivos = {120.0, 300.0} (qtd_pos =
2) e negativos = {-45.5, -80.0} (qtd_neg = 2).
■ Dica: use um ponteiro auxiliar para percorrer o vetor de entrada e ponteiros independentes para escrever
em cada vetor de saída.

*/

void separa_transacoes(float *valores, int n, float *positivos, int *qtd_pos,
float *negativos, int *qtd_neg){
    int i;
    *qtd_neg = 0;
    *qtd_pos = 0;
    float *auxiliar = valores;

    for(i = 0; i < n; i++){
        if(*auxiliar > 0){
            *positivos = *auxiliar;
            *qtd_pos += 1;
            positivos++;
        } else if (*auxiliar < 0) {
            *negativos = *auxiliar;
            *qtd_neg += 1;
            negativos++;
        }
        auxiliar++;
    }
}

int main(){
    float vetor[] = {120.0, -45.5, 0.0, 300.0, -80.0};
    int qtd = 5;
    int qtdPos, qtdNeg;
    float pos[5];
    float neg[5];
    return 0;
}