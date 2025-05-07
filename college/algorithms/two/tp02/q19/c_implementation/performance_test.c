/**
 * performance_test.c
 * Funções para testar o desempenho dos algoritmos de ordenação
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sorting_algorithms.h"

/**
 * Gera um array de números aleatórios
 *
 * @param size Tamanho do array
 * @return Ponteiro para o array gerado
 */
int *generate_random_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < size; i++) {
        arr[i] =
            rand() % 1000000 + 1;  // Números aleatórios entre 1 e 1.000.000
    }

    return arr;
}

/**
 * Verifica se um array está ordenado
 *
 * @param arr Array a ser verificado
 * @param n Tamanho do array
 * @return 1 se ordenado, 0 caso contrário
 */
int is_sorted(int *arr, int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Executa um algoritmo de ordenação e verifica o resultado
 *
 * @param algorithm Ponteiro para a função do algoritmo
 * @param arr Array a ser ordenado
 * @param n Tamanho do array
 * @param algorithm_name Nome do algoritmo (para depuração)
 * @return Estrutura com os resultados (comparações, movimentações, tempo)
 */
SortResult run_algorithm(SortResult (*algorithm)(int *, int), int *arr, int n,
                         const char *algorithm_name) {
    int *test_arr = (int *)malloc(n * sizeof(int));
    if (test_arr == NULL) {
        fprintf(stderr, "Erro na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    // Copia o array original para não modificá-lo
    memcpy(test_arr, arr, n * sizeof(int));

    // Executa o algoritmo
    SortResult result = algorithm(test_arr, n);

    // Verifica se o array está ordenado
    if (!is_sorted(test_arr, n)) {
        fprintf(stderr, "ERRO: %s falhou em ordenar o array corretamente!\n",
                algorithm_name);
    }

    free(test_arr);
    return result;
}

/**
 * Executa testes de desempenho para todos os algoritmos
 *
 * @param sizes Array com os tamanhos a serem testados
 * @param num_sizes Número de tamanhos diferentes
 * @param results_dir Diretório para salvar os resultados
 */
void run_performance_tests(int *sizes, int num_sizes, const char *results_dir) {
    // Definir os algoritmos e seus nomes
    SortResult (*algorithms[])(int *, int) = {selection_sort, insertion_sort,
                                              bubble_sort, quick_sort};
    const char *algorithm_names[] = {"selection_sort", "insertion_sort",
                                     "bubble_sort", "quick_sort"};
    int num_algorithms = 4;

    // Arrays para armazenar os resultados
    SortResult ***results =
        (SortResult ***)malloc(num_algorithms * sizeof(SortResult **));
    int i, j;

    // Inicializar a matriz de resultados
    for (i = 0; i < num_algorithms; i++) {
        results[i] = (SortResult **)malloc(num_sizes * sizeof(SortResult *));
        for (j = 0; j < num_sizes; j++) {
            results[i][j] = (SortResult *)malloc(sizeof(SortResult));
        }
    }

    // Para cada tamanho de array
    for (i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        printf("\nTestando com array de tamanho %d...\n", size);

        // Gerar array aleatório
        int *arr = generate_random_array(size);

        // Executar cada algoritmo
        for (j = 0; j < num_algorithms; j++) {
            printf("  Executando %s...\n", algorithm_names[j]);
            *(results[j][i]) =
                run_algorithm(algorithms[j], arr, size, algorithm_names[j]);
            printf("  %s concluído em %.6f segundos\n", algorithm_names[j],
                   results[j][i]->execution_time);
        }

        // Liberar memória do array
        free(arr);
    }

    // Criar diretório para resultados se não existir
    char command[256];
    sprintf(command, "mkdir -p %s", results_dir);
    system(command);

    // Salvar resultados em arquivos CSV individuais para cada algoritmo
    for (i = 0; i < num_algorithms; i++) {
        char filename[256];
        sprintf(filename, "%s/%s_results.csv", results_dir, algorithm_names[i]);

        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            fprintf(stderr, "Erro ao abrir arquivo %s para escrita\n",
                    filename);
            continue;
        }

        // Escrever cabeçalho
        fprintf(file, "size,execution_time_s,comparisons,movements\n");

        // Escrever dados
        for (j = 0; j < num_sizes; j++) {
            fprintf(file, "%d,%f,%llu,%llu\n", sizes[j],
                    results[i][j]->execution_time, results[i][j]->comparisons,
                    results[i][j]->movements);
        }

        fclose(file);
        printf("Resultados para %s salvos em %s\n", algorithm_names[i],
               filename);
    }

    // Salvar resultados em um único arquivo CSV para todos os algoritmos
    char combined_filename[256];
    sprintf(combined_filename, "%s/combined_results.csv", results_dir);

    FILE *combined_file = fopen(combined_filename, "w");
    if (combined_file == NULL) {
        fprintf(stderr, "Erro ao abrir arquivo %s para escrita\n",
                combined_filename);
    } else {
        // Escrever cabeçalho
        fprintf(combined_file, "size");
        for (i = 0; i < num_algorithms; i++) {
            fprintf(combined_file,
                    ",%s_execution_time_s,%s_comparisons,%s_movements",
                    algorithm_names[i], algorithm_names[i], algorithm_names[i]);
        }
        fprintf(combined_file, "\n");

        // Escrever dados
        for (j = 0; j < num_sizes; j++) {
            fprintf(combined_file, "%d", sizes[j]);

            for (i = 0; i < num_algorithms; i++) {
                fprintf(combined_file, ",%f,%llu,%llu",
                        results[i][j]->execution_time,
                        results[i][j]->comparisons, results[i][j]->movements);
            }

            fprintf(combined_file, "\n");
        }

        fclose(combined_file);
        printf("Resultados combinados salvos em %s\n", combined_filename);
    }

    // Liberar memória dos resultados
    for (i = 0; i < num_algorithms; i++) {
        for (j = 0; j < num_sizes; j++) {
            free(results[i][j]);
        }
        free(results[i]);
    }
    free(results);
}