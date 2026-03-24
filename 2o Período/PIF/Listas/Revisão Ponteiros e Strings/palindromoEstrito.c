/*

10. O Oráculo dos Espelhos — Palíndromo Estrito
Numa antiga biblioteca digital, diz a lenda que frases que se leem iguais nos dois sentidos
abrem portas secretas — os chamados palíndromos. O sistema de segurança precisa
validar essas frases com precisão máxima: ignorando espaços e sem distinção entre
maiúsculas e minúsculas.
Escreva eh_palindromo_estrito usando dois ponteiros simultâneos: inicio (começo da
string) e fim (último caractere antes do '\0'), convergindo ao centro. Espaços devem ser
pulados. Maiúsculas e minúsculas tratadas como iguais usando aritmética ASCII. Retorne
1 ou 0.
Estrutura:
int eh_palindromo_estrito(char *str);
Exemplos:
"A man a plan a canal Panama" → 1
"Socorram me subi no onibus em Marrocos" → 1
"hello" → 0
Restrição: proibido usar strlen(), tolower() ou qualquer função de string.h.
Dica: 'A' = 65, 'a' = 97, diferença = 32. Se o char está entre 'A' e 'Z', some 32 antes de
comparar.

*/

int eh_palindromo_estrito(char *str){
    char *tudoMinusculo = str;

    while(*tudoMinusculo != '\0'){
        if (*tudoMinusculo >= 'A' && *tudoMinusculo <= 'Z'){
            *tudoMinusculo += 32;
        }
        tudoMinusculo++;
    }

    int numeroDeCaracteres = 0;
    char *contaCaracteres = str;

    while (*contaCaracteres != '\0'){
        numeroDeCaracteres++;
        contaCaracteres++;
    }

    char *inicio = str;
    char *final = str + numeroDeCaracteres - 1;;

    int i;
    while (inicio < final) {
        while (*inicio == ' ') inicio++;
        while (*final == ' ') final--;
        
        if (*inicio != *final) return 0;
        
        inicio++;
        final--;
    }

    return 1;
}