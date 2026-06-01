#include <stdio.h>
#include "livros.h"

#define VEC_SIZE 10

int main(){
    struct Livro vet_livros[VEC_SIZE];
    struct Livro liv;
    for(int i = 0; i<VEC_SIZE; i++){
        inserir_livro(liv, vet_livros);
    }
    return 0;
}