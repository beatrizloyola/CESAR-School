#include "livros.h" // <biblioteca padrão>, "diretório atual"

void inserir_livro(struct Livro livro, struct Livro *vet_livro, int posicao){
    vet_livro[posicao] = livro;
}


void remover_livro(int id, struct Livro *vet_livro, int tamanho_vet){
    for (int i = 0; i < tamanho_vet; i++){
        if (vet_livro[i].id == id){
            for (int j = i; j < tamanho_vet - 1; j++) {
                vet_livro[j] = vet_livro[j + 1];
            }
        }
    }
}