/*

8. A União dos Pergaminhos — Concatenação Manual
Na biblioteca central, dois registros textuais precisam ser unidos em um único documento
contínuo. Porém, o sistema está em modo restrito e não permite o uso de funções prontas
da biblioteca de strings.
Escreva um programa em C que leia duas strings fornecidas pelo usuário, cada uma com
até 100 caracteres. Implemente uma função que receba duas strings e concatene a
segunda ao final da primeira, sem utilizar funções da biblioteca padrão (como ‘strcat’). A
string destino deve possuir espaço suficiente para armazenar o resultado final. O processo
deve ser feito utilizando aritmética de ponteiros.
Estrutura:
void concatenar(char *destino, char *origem);
Exemplo de Entrada:
Casa
Azul
Exemplo de Saída:
CasaAzul
Restrição: não utilizar funções prontas de manipulação de strings.

*/

#include <stdio.h>

void concatenar(char *destino, char *origem){
    
    while(*destino != '\n'){
        destino++;
    }
    *destino = '\0';

    while(*origem != '\0'){
        *destino = *origem;
        origem++;
        destino++;
    }
}

int main(){
    char destino[100];
    char origem[100];

    printf("Destino: ");
    fgets(destino, 100, stdin);
    printf("\nOrigem: ");
    fgets(origem, 100, stdin);

    concatenar(destino, origem);
    printf("%s", destino);

    return 0;
}