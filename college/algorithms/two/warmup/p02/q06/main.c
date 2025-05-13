#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um nó da lista ligada
typedef struct No {
    char aviao[10];
    struct No* proximo;
} No;

// Função para criar um novo nó
No* criarNo(char* aviao) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    strcpy(novoNo->aviao, aviao);
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para inserir um avião no final de uma lista
void inserirAviao(No** cabeca, char* aviao) {
    No* novoNo = criarNo(aviao);

    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }

    No* atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novoNo;
}

// Função para liberar memória da lista ligada
void liberarLista(No* cabeca) {
    No* atual = cabeca;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    int pontoCardeal;
    char aviao[10];

    // Listas para cada ponto cardeal
    No* oeste = NULL;  // -1
    No* sul = NULL;    // -2
    No* norte = NULL;  // -3
    No* leste = NULL;  // -4

    scanf("%d", &pontoCardeal);

    while (pontoCardeal != 0) {
        // Lê o identificador do avião
        scanf("%s", aviao);

        // Insere o avião na lista correspondente ao ponto cardeal
        switch (pontoCardeal) {
            case -1:  // Oeste
                inserirAviao(&oeste, aviao);
                break;
            case -2:  // Sul
                inserirAviao(&sul, aviao);
                break;
            case -3:  // Norte
                inserirAviao(&norte, aviao);
                break;
            case -4:  // Leste
                inserirAviao(&leste, aviao);
                break;
        }

        scanf("%d", &pontoCardeal);
    }

    // Montagem da fila final de acordo com o protocolo

    // 1. Primeiro os aviões do Oeste (maior prioridade)
    No* atual = oeste;
    while (atual != NULL) {
        printf("%s ", atual->aviao);
        atual = atual->proximo;
    }

    // 2. Alternando entre Norte e Sul
    No* atualNorte = norte;
    No* atualSul = sul;

    // Começando com Norte
    int vezDoNorte = 1;

    while (atualNorte != NULL || atualSul != NULL) {
        if (vezDoNorte) {
            if (atualNorte != NULL) {
                printf("%s ", atualNorte->aviao);
                atualNorte = atualNorte->proximo;
            }
            vezDoNorte = 0;
        } else {
            if (atualSul != NULL) {
                printf("%s ", atualSul->aviao);
                atualSul = atualSul->proximo;
            }
            vezDoNorte = 1;
        }

        // Se uma das filas estiver vazia, continue alternando corretamente
        if (atualNorte == NULL && atualSul == NULL) {
            break;
        } else if (atualNorte == NULL) {
            // Se Norte está vazio mas ainda há aviões do Sul
            if (!vezDoNorte) {
                continue;
            }
        } else if (atualSul == NULL) {
            // Se Sul está vazio mas ainda há aviões do Norte
            if (vezDoNorte) {
                continue;
            }
        }
    }

    // 3. Por último, os aviões do Leste (menor prioridade)
    atual = leste;
    while (atual != NULL) {
        printf("%s ", atual->aviao);
        atual = atual->proximo;
    }

    printf("\n");

    // Libera a memória alocada
    liberarLista(oeste);
    liberarLista(sul);
    liberarLista(norte);
    liberarLista(leste);

    return 0;
}