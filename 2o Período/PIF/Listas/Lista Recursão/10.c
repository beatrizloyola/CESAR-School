#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int valor;
    struct node *next;
} node;

void gravaInvertido(node *p, FILE *out) {
    if (p == NULL) {
        return;
    }

    gravaInvertido(p->next, out);
    fprintf(out, "%d\n", p->valor);
}

int main() {
    FILE *in = fopen("numeros.txt", "r");
    FILE *out = fopen("invertido.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    node *head = NULL;
    node *tail = NULL;

    int numero;

    while (fscanf(in, "%d", &numero) == 1) {
        node *novo = malloc(sizeof(node));

        novo->valor = numero;
        novo->next = NULL;

        if (head == NULL) {
            head = novo;
            tail = novo;
        } else {
            tail->next = novo;
            tail = novo;
        }
    }

    gravaInvertido(head, out);

    fclose(in);
    fclose(out);

    while (head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}