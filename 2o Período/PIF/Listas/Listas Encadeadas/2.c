typedef struct node{
    int valor;
    struct node *next;
}node;

void adiciona_inicio(node **head, int valor){
    node *novo = (node*)malloc(sizeof(node));

    novo->valor = valor;
    novo->next = *head;
    *head = novo;
}