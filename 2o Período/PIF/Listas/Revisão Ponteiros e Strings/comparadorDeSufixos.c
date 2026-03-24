/*

6. O Verificador de Documentos — Comparador de Sufixos
Um sistema de arquivamento precisa classificar documentos pelo sufixo de seus nomes:
.pdf, .txt, .exe... O problema: a biblioteca padrão foi removida do ambiente restrito. Você
precisa recriar a lógica do zero.
Crie a função compara_sufixo que verifica se str termina exatamente com o conteúdo de
sufixo. Para encontrar os comprimentos, itere os ponteiros até o '\0'. Retorne 1
(verdadeiro) ou 0 (falso).
Estrutura:
int compara_sufixo(char *str, char *sufixo);

Exemplos:
compara_sufixo("relatorio.pdf", ".pdf") → 1
compara_sufixo("imagem.png", ".jpg") → 0.
Restrição: proibido usar qualquer função de string.h.

*/

#include <stdio.h>

int compara_sufixo(char *str, char *sufixo){
    int tamanhoStr = 0;
    while (*str != '\0'){
        tamanhoStr++;
        str++;
    }
    str -= tamanhoStr;

    int tamanhoSufixo = 0;
    while (*sufixo != '\0'){
        tamanhoSufixo++;
        sufixo++;
    }
    sufixo -= tamanhoSufixo;

    str += (tamanhoStr - tamanhoSufixo);

    int i;
    for(i = 0; i < tamanhoSufixo; i++){
        if (*str != *sufixo){
            return 0;
        } else {
            str++;
            sufixo++;
        }
    }
    return 1;
}

int main(){
    char str1[] = "coisinha.pdf";
    char str2[] = ".pfd";
    char str3[] = ".pdf";

    printf("%d %d", compara_sufixo(str1, str2), compara_sufixo(str1, str3));

    return 0;
}