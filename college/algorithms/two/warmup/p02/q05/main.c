#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um intervalo
typedef struct {
    int inicio;
    int fim;
} Intervalo;

// Função de comparação para ordenar os intervalos
int compararIntervalos(const void *a, const void *b) {
    Intervalo *intervaloA = (Intervalo *)a;
    Intervalo *intervaloB = (Intervalo *)b;
    return intervaloA->inicio - intervaloB->inicio;
}

// Função para mesclar intervalos sobrepostos
void mesclarIntervalos(Intervalo intervalos[], int n, Intervalo resultado[],
                       int *tamanhoResultado) {
    // Se não houver intervalos, retornar
    if (n <= 0) {
        *tamanhoResultado = 0;
        return;
    }

    // Ordenar intervalos com base no ponto inicial
    qsort(intervalos, n, sizeof(Intervalo), compararIntervalos);

    // Inicializar tamanhoResultado
    *tamanhoResultado = 0;

    // Adicionar o primeiro intervalo ao resultado
    resultado[0] = intervalos[0];
    (*tamanhoResultado)++;

    // Mesclar intervalos sobrepostos
    for (int i = 1; i < n; i++) {
        // Obter o último intervalo no resultado
        Intervalo *ultimoIntervalo = &resultado[(*tamanhoResultado) - 1];

        // Se o intervalo atual não se sobrepõe ao último intervalo,
        // adicioná-lo ao resultado
        if (intervalos[i].inicio > ultimoIntervalo->fim) {
            resultado[(*tamanhoResultado)] = intervalos[i];
            (*tamanhoResultado)++;
        }
        // Caso contrário, atualizar o fim do último intervalo se necessário
        else if (intervalos[i].fim > ultimoIntervalo->fim) {
            ultimoIntervalo->fim = intervalos[i].fim;
        }
    }
}

int main() {
    int P, S;  // P: comprimento da praia, S: número de sorveteiros
    int casoTeste = 1;

    while (1) {
        scanf("%d %d", &P, &S);

        // Verificar o fim da entrada
        if (P == 0 && S == 0) {
            break;
        }

        Intervalo intervalos[S];
        Intervalo intervalosMesclados[S];  // O número máximo de intervalos
                                           // mesclados é S
        int tamanhoMesclado;

        // Ler intervalos para cada sorveteiro
        for (int i = 0; i < S; i++) {
            scanf("%d %d", &intervalos[i].inicio, &intervalos[i].fim);
        }

        // Mesclar intervalos sobrepostos
        mesclarIntervalos(intervalos, S, intervalosMesclados, &tamanhoMesclado);

        // Imprimir o resultado
        printf("Teste %d\n", casoTeste++);
        for (int i = 0; i < tamanhoMesclado; i++) {
            printf("%d %d\n", intervalosMesclados[i].inicio,
                   intervalosMesclados[i].fim);
        }
        printf("\n");
    }

    return 0;
}