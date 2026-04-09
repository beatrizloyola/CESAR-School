/*

Defina uma struct chamada Ponto contendo:
● int x
● int y
Implemente uma função chamada somar_pontos. A função deve receber como parâmetros:
● duas structs do tipo Ponto
A função deve retornar:
● uma struct Ponto com a soma das coordenadas:
○ x = x1 + x2
○ y = y1 + y2
Protótipo da função:
Ponto somar_pontos(Ponto a, Ponto b);
Implemente uma função main() que:
1. leia dois pontos;
2. chame a função somar_pontos;
3. imprima o ponto resultante.

*/

#include <stdio.h>
#include <stdlib.h>

struct Ponto{
    int x;
    int y;
};

struct Ponto somar_pontos(struct Ponto p1, struct Ponto p2){
    struct Ponto resultado;
    resultado.x = p1.x + p2.x;
    resultado.y = p1.y + p2.y;
    return resultado;
}

int main(){
    struct Ponto p1 = {2,2};
    struct Ponto p2 = {3,4};
    struct Ponto resultado = somar_pontos(p1,p2);
    printf("%d %d", resultado.x, resultado.y);
}
