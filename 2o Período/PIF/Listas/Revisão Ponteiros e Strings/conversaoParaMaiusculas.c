/*

4. A Forja das Letras — Conversão para Maiúsculas
Em uma oficina de impressão real, todo texto oficial precisa ser gravado em letras
maiúsculas. Sua tarefa é automatizar a forja tipográfica, convertendo apenas as letras
minúsculas, sem alterar números, espaços ou símbolos.
Escreva um programa em C que leia uma string. Crie uma função que converta todas as
letras minúsculas dessa string para maiúsculas. Letras que já são maiúsculas, números e
outros símbolos não devem ser alterados.
Dica: na tabela ASCII, a distância entre uma letra minúscula e sua respectiva
maiúscula é um valor constante. Por exemplo, 'a' - 'A' = 32 ou 'a' - 32 = 'A'.
Estrutura:
void paraMaiusculas(char *str);

Exemplo de Entrada:
Ponteiros e Strings 2024!
Exemplo de Saída:
PONTEIROS E STRINGS 2024!
Restrição: a função deve modificar a própria string recebida utilizando aritmética de
ponteiros.

*/

#include <stdio.h>

void paraMaiusculas(char *str){
    while (*str != '\0'){
        if (*str >= 'a' && *str <= 'z'){
            *str -= 32;
        }
        str++;
    }
}

int main(){
    char str[] = "Ponteiros e Strings 2024!";
    paraMaiusculas(str);
    printf("%s", str);

    return 0;
}