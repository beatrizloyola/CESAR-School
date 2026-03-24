/*

9. A Censura In-Place — Remoção de Caractere
Um sistema de moderação precisa remover caracteres indesejáveis de mensagens já
armazenadas na memória. O desafio: tudo deve ocorrer na própria string, sem criar uma
segunda string auxiliar.
Implemente remove_ocorrencias, que remove todas as ocorrências do caractere alvo da
string original movendo os caracteres restantes para a esquerda com dois ponteiros: um de
leitura e um de escrita. Retorne o total de caracteres removidos.
Estrutura:
int remove_ocorrencias(char *str, char alvo);
Exemplo:
remove_ocorrencias("banana", 'a') → string vira "bnn", retorno = 3.

*/

#include <stdio.h>

int remove_ocorrencias(char *str, char alvo){
    char *leitura = str;
    char *escrita = str;
    int contador = 0;

    while(*leitura != '\0'){
        if (*leitura != alvo){
            *escrita = *leitura;
            escrita++;
        } else {
            contador++;
        }
        leitura++;
    }

    *escrita = '\0';

    return contador;
}

int main(){
    char banana[] = "banana";
    printf("%d ", remove_ocorrencias(banana, 'a'));
    printf("%s", banana);

    return 0;
}