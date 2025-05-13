#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* proximo;
} Node;

typedef struct Lista {
    Node* cabeca;
} Lista;

Node* inverterLista(Node* cabeca) {
    Node* anterior = NULL;
    Node* atual = cabeca;
    Node* proximo = NULL;

    while (atual != NULL) {
        // Guarda o próximo nó antes de modificar
        proximo = atual->proximo;

        // Inverte a ligação atual
        atual->proximo = anterior;

        // Avança os ponteiros para a próxima iteração
        anterior = atual;
        atual = proximo;
    }

    // anterior agora é a nova cabeça da lista invertida
    return anterior;
}

Node* imprimirLista(Node* cabeca) {
    Node* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

Node* criarNo(int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

int main() {
    // Criando uma lista encadeada simples
    Node* cabeca = criarNo(1);
    cabeca->proximo = criarNo(2);
    cabeca->proximo->proximo = criarNo(3);
    cabeca->proximo->proximo->proximo = criarNo(4);
    cabeca->proximo->proximo->proximo->proximo = criarNo(5);

    printf("Lista original: ");
    imprimirLista(cabeca);

    // Invertendo a lista
    cabeca = inverterLista(cabeca);

    printf("Lista invertida: ");
    imprimirLista(cabeca);

    // Liberando a memória alocada
    Node* atual = cabeca;
    while (atual != NULL) {
        Node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}