/*
Implemente, em linguagem C, uma lista telefônica utilizando uma lista encadeada,
na qual cada contato deve armazenar nome e número de telefone.

Os contatos devem ser mantidos sempre em ordem alfabética pelo nome, ou seja, a inserção de novos contatos deve
respeitar essa ordenação automaticamente.

Seu programa deve oferecer, no mínimo, as seguintes funcionalidades:
- Inserir um novo contato na lista
- Buscar um contato pelo nome
- Exibir todos os contatos cadastrados
- Excluir contato

Na operação de busca, caso o nome informado não esteja presente na lista, o programa deve exibir uma
mensagem informando que o contato não foi encontrado.

Requisitos adicionais:
Não permitir nomes duplicados (opcional, se quiser aumentar a dificuldade)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato{
    int numero;
    char nome[100];
    struct contato *next;
} contato ;

int buscarPorNumero(contato *head, int numeroContato){
    contato *percorre = head;
    while (percorre != NULL){
        if (percorre -> numero == numeroContato){
            printf("Contato encontrado: %s\n", percorre->nome);
            return 1;
        } else {
            percorre = percorre -> next;
        }
    return 0;
    
    }
}

void inserirNoFinal(contato **head, char *nomeContato, int numeroContato){
    if (buscarPorNumero(*head, numeroContato) == 0){

        contato *novo = (contato *)malloc(sizeof(contato));
        novo -> numero = numeroContato;
        strcpy(novo -> nome, nomeContato);
        novo -> next = NULL;

        if (*head == NULL){
            *head = novo;
        } else {
            contato *percorrer = *head;
            while (percorrer -> next != NULL){
                percorrer = percorrer -> next;
            }
            percorrer -> next = novo;
        }
        
    } else {
        printf("Contato já existe.\n");
    }

}

void inserirOrdemAlfabetica(contato **head, char *nomeContato, int numeroContato){
    if (buscarPorNumero(*head, numeroContato) == 0){

        
        contato *novo = (contato *)malloc(sizeof(contato));
        novo -> numero = numeroContato;
        strcpy(novo -> nome, nomeContato);
        novo -> next = NULL;

         // Inserção no início
        if (*head == NULL || strcmp(nomeContato, (*head)->nome) < 0){
            novo->next = *head;
            *head = novo;
            return;
        }

        contato *percorrer = *head;

        // Procura posição correta
        while (percorrer->next != NULL &&
               strcmp(nomeContato, percorrer->next->nome) > 0){
            percorrer = percorrer->next;
        }

        // Inserção
        novo->next = percorrer->next;
        percorrer->next = novo;


    } else {
        printf("Contato já existe.\n");
    }
}

void exibir(contato *head){
    contato *percorrer = head;
    while(percorrer != NULL){
        printf("Nome: %s | Número: %d\n", percorrer -> nome, percorrer -> numero);
        percorrer = percorrer -> next;
    }
}

void excluir(contato **head, char *nomeContato){
    contato *atual = *head;
    contato *anterior = NULL;
    
    while (atual != NULL){

        if (strcmp(atual->nome, nomeContato) == 0){

            if (anterior == NULL){
                *head = atual -> next;
            } else {
                anterior -> next = atual -> next;
            }

        free(atual);
        printf("Contato excluído\n");
        return;
        }

    anterior = atual;
    atual = atual -> next;
    }
}

int main(){

    contato *lista = NULL;

    inserirOrdemAlfabetica(&lista, "Ana", 1111);
    inserirOrdemAlfabetica(&lista, "Carlos", 2222);
    inserirOrdemAlfabetica(&lista, "Bruno", 3333);

    exibir(lista);

    buscarPorNumero(lista, 2222);

    excluir(&lista, "Carlos");

    printf("\nDepois da exclusão:\n");

    exibir(lista);

    return 0;
}