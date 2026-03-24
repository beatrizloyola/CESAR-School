// Não consegui fazer sozinha :(

/*

7. O Detector de Fragmentos — Busca por Substring
Um sistema de inteligência precisa verificar se uma palavra-chave secreta aparece em um
documento maior. A palavra pode surgir logo no início, no meio ou no final do texto — e sua
função deve ser capaz de encontrá-la em qualquer posição.
Escreva um programa em C que leia duas strings: uma string principal e uma substring.
Crie uma função que verifique se a substring aparece em qualquer posição da string
principal.
Exemplos:
"programacao" e "pro" → 1
"programacao" e "grama" → 1
"programacao" e "acao" → 1
"ponteiro" e "teia" → 0
A função deve retornar:
● 1 se a substring estiver contida na string principal
● 0 caso contrário
Estrutura:
int contemSubstring(char *str, char *sub);
Dica: percorra a string principal e, em cada posição, tente verificar se a substring
começa ali.

*/

int contemSubstring(char *str, char *sub){
    char *auxiliarSub = sub;

    while(*str != '\0'){
        char *auxiliarStr = str;  // ← agora salva a posição correta a cada tentativa
        sub = auxiliarSub;        // ← reinicia sub a cada tentativa

        while (*sub != '\0' && *auxiliarStr == *sub){
            auxiliarStr++;
            sub++;
        }

        if (*sub == '\0'){  // ← chegou ao fim da substring → achou
            return 1;
        }

        str++;  // ← avança na string principal
    }

    return 0;
}