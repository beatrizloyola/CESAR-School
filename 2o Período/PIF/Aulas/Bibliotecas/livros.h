/*

Crie uma biblioteca que define uma estrutura chamada livro,
contendo id (inteiro), nome (string tamanho 100), autor (string
tamanho 100) e paginas (inteiro), com funções para inserir os livros
ordenadamente por id, remover um livro de acordo com seu id e
listar os livros cadastrados.
● Crie um programa que usa essa biblioteca para fazer um cadastro
de livros.

*/

struct Livro{
    int id;
    char nome[100];
    char autor[100];
    int paginas;
};

void inserir_livro(struct Livro, struct Livro *vet_livro);
void remover_livro(int id, struct Livro *vet_livro);