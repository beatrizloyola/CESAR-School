/*

4. O Embaralhador de Registros — Intercalação de Vetores
Um sistema de áudio digital precisa intercalar duas faixas de amostras em um único buffer de saída
— técnica conhecida como interleaving. Os elementos das duas faixas devem aparecer alternados
no vetor resultante: primeiro um elemento de A, depois um de B, e assim por diante.
Escreva a função intercala, que recebe dois vetores de floats a e b, ambos de tamanho n, e um
vetor de saída resultado com espaço para 2*n elementos. A função deve preencher o vetor
resultado intercalando os elementos de a e b usando exclusivamente aritmética de ponteiros. A
função não possui retorno.
void intercala(float *a, float *b, float *resultado, int n);
Exemplo: a = {1.0, 3.0, 5.0}, b = {2.0, 4.0, 6.0} → resultado = {1.0, 2.0, 3.0,
4.0, 5.0, 6.0}.
■ Restrição: proibido usar o operador []. Use apenas aritmética de ponteiros para leitura e escrita em
todos os vetores.
■ Dica: um ponteiro percorre a e outro percorre b; um terceiro ponteiro de escrita avança no resultado. A cada
iteração, escreva um elemento de cada fonte.

*/

void intercala(float *a, float *b, float *resultado, int n){
    int i;
    for (i = 0; i < n; i++){
        *resultado = *a;
        resultado++;
        a++;
        *resultado = *b;
        resultado++;
        b++;
    }
}