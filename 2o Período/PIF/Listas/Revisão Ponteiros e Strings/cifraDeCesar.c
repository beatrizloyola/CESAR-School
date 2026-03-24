/*

2. A Máquina Enigma Simplificada — Cifra de César
Durante a Segunda Guerra Mundial, máquinas de criptografia mudaram o curso da história.
Você foi encarregado de implementar uma versão minimalista: a Cifra de César, que
desloca cada caractere da mensagem por um valor fixo na tabela ASCII.
Escreva a função cifra_cesar que recebe um ponteiro para uma string e um inteiro
deslocamento. A função deve modificar a string in-place somando o deslocamento ao
código ASCII de cada caractere, e retornar o ponteiro para a própria string modificada.
Estrutura:
char *cifra_cesar(char *str, int deslocamento);
Exemplo:
cifra_cesar("abc", 3) → "def".
Restrição: não crie uma cópia da string. Toda modificação deve ocorrer no buffer
original.

*/

char *cifra_cesar(char *str, int deslocamento){
    while (*str !=  '\0'){
        *str += deslocamento;
        str++;
    }
}

int main(){
    char frase[] = "abc";
    cifra_cesar(frase, 3);
    printf("%s", frase);

    return 0;
}