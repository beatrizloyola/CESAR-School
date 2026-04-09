/*

Defina uma struct chamada Produto contendo:
● char nome[50]
● float preco
● int quantidade
Implemente uma função chamada buscar_produto_mais_caro.
A função deve receber como parâmetros:
● um vetor de structs do tipo Produto;
● um inteiro n, representando a quantidade de produtos no vetor.
A função deve retornar:
● a posição do produto com maior preço no vetor.

Considere que:
● se houver empate, deve ser retornada a primeira posição encontrada.
Protótipo da função:
int buscar_produto_mais_caro(Produto v[], int n);

*/

#include <stdio.h>

struct Produto{
    char nome[50];
    float preco;
    int quantidade;
};

int buscar_produto_mais_caro(struct Produto v[], int n){
    int indice = 0;
    float maiorPreco = v[0].preco;
    for (int i = 1; i < n; i++){
        if (v[i].preco > maiorPreco){
            maiorPreco = v[i].preco;
            indice = i;
        }
    }
    return indice;
}

/*

Implemente uma função main() que:
1. leia um inteiro n;
2. declare um vetor de Produto com n posições;
3. leia os dados de todos os produtos;
4. chame a função buscar_produto_mais_caro;
5. imprima o nome, o preço e a quantidade do produto encontrado.

*/

int main(){
    int n;
    printf("n: ");
    scanf("%d", &n);

    struct Produto vetor[n];

    for(int i = 0; i < n; i++){
        printf("\n%do produto\n", i+1);
        printf("Nome: ");
        scanf("%s", vetor[i].nome);
        printf("Preço: ");
        scanf("%f", &vetor[i].preco);
        printf("Quantidade: ");
        scanf("%d", &vetor[i].quantidade);
    }

    int maisCaro = buscar_produto_mais_caro(vetor, n);
    printf("\nProduto mais caro\n");
    printf("Nome: %s\nPreço: %.2f\nQuantidade: %d", vetor[maisCaro].nome, vetor[maisCaro].preco, vetor[maisCaro].quantidade);
    return 0;
}