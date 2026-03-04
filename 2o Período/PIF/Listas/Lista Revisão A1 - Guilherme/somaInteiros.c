/*
Crie uma função chamada soma() que receba dois números inteiros como parâmetros e retorne a soma.
Na main, leia dois valores do usuário, chame a função e imprima o resultado.
*/

int funcao(int a, int b){
    return a + b;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", funcao(a, b));
}