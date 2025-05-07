/**
 * sorting_algorithms.h
 * Declarações de algoritmos de ordenação com contadores de comparações e
 * movimentações
 */

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdlib.h>

/**
 * Estrutura para armazenar resultados dos algoritmos de ordenação
 */
typedef struct {
    unsigned long long comparisons;  // Número de comparações
    unsigned long long movements;    // Número de movimentações
    double execution_time;           // Tempo de execução em segundos
} SortResult;

/**
 * Selection Sort (Ordenação por Seleção)
 *
 * @param arr Array a ser ordenado
 * @param n Tamanho do array
 * @return Estrutura com os resultados (comparações, movimentações, tempo)
 */
SortResult selection_sort(int *arr, int n);

/**
 * Insertion Sort (Ordenação por Inserção)
 *
 * @param arr Array a ser ordenado
 * @param n Tamanho do array
 * @return Estrutura com os resultados (comparações, movimentações, tempo)
 */
SortResult insertion_sort(int *arr, int n);

/**
 * Bubble Sort (Ordenação por Bolha)
 *
 * @param arr Array a ser ordenado
 * @param n Tamanho do array
 * @return Estrutura com os resultados (comparações, movimentações, tempo)
 */
SortResult bubble_sort(int *arr, int n);

/**
 * Quick Sort (Ordenação Rápida)
 *
 * @param arr Array a ser ordenado
 * @param n Tamanho do array
 * @return Estrutura com os resultados (comparações, movimentações, tempo)
 */
SortResult quick_sort(int *arr, int n);

#endif /* SORTING_ALGORITHMS_H */