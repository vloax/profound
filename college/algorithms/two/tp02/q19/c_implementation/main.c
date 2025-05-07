/**
 * main.c
 * Programa principal para executar os testes de ordenação
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sorting_algorithms.h"

// Declaração de função definida em performance_test.c
void run_performance_tests(int *sizes, int num_sizes, const char *results_dir);

int main(int argc, char *argv[]) {
    // Inicializar o gerador de números aleatórios
    srand(42);  // Usar uma semente fixa para reprodutibilidade

    // Definir os tamanhos dos arrays a serem testados
    int sizes[] = {100, 1000, 10000, 100000};
    int num_sizes = 4;

    // Diretório para salvar os resultados (padrão: "../results")
    const char *results_dir = "../results";

    // Verificar se foi fornecido um diretório de saída como argumento
    if (argc > 1) {
        results_dir = argv[1];
    }

    printf("===========================================================\n");
    printf("ANÁLISE COMPARATIVA DE ALGORITMOS DE ORDENAÇÃO\n");
    printf("===========================================================\n");

    printf("\nExecutando testes para os seguintes tamanhos: ");
    int i;
    for (i = 0; i < num_sizes; i++) {
        printf("%d ", sizes[i]);
    }
    printf("\n");

    printf("\nOs resultados serão salvos em: %s\n", results_dir);

    // Medir o tempo total de execução
    clock_t start_time = clock();

    // Executar os testes
    run_performance_tests(sizes, num_sizes, results_dir);

    // Calcular o tempo total
    double total_time = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

    printf("\nTestes concluídos em %.2f segundos.\n", total_time);
    printf("===========================================================\n");

    return 0;
}