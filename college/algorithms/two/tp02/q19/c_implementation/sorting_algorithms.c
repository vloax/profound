/**
 * sorting_algorithms.c
 * Implementação de algoritmos de ordenação com contadores de comparações e
 * movimentações
 */

#include "sorting_algorithms.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Selection Sort (Ordenação por Seleção)
 */
SortResult selection_sort(int *arr, int n) {
    SortResult result = {0, 0, 0.0};
    int i, j, min_idx;

    // Medir tempo de início
    clock_t start_time = clock();

    // Algoritmo Selection Sort
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            result.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Trocar o elemento mínimo com o primeiro elemento não ordenado
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            result.movements++;
        }
    }

    // Calcular tempo de execução em segundos
    result.execution_time = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

    return result;
}

/**
 * Insertion Sort (Ordenação por Inserção)
 */
SortResult insertion_sort(int *arr, int n) {
    SortResult result = {0, 0, 0.0};
    int i, j, key;

    // Medir tempo de início
    clock_t start_time = clock();

    // Algoritmo Insertion Sort
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Cada verificação de condição conta como uma comparação
        result.comparisons++;

        // Mover elementos maiores que key para uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            result.movements++;
            j--;

            // Se não chegamos ao fim do array, temos outra comparação
            if (j >= 0) {
                result.comparisons++;
            }
        }

        if (j + 1 != i) {
            arr[j + 1] = key;
            result.movements++;
        }
    }

    // Calcular tempo de execução em segundos
    result.execution_time = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

    return result;
}

/**
 * Bubble Sort (Ordenação por Bolha)
 */
SortResult bubble_sort(int *arr, int n) {
    SortResult result = {0, 0, 0.0};
    int i, j;
    int swapped;

    // Medir tempo de início
    clock_t start_time = clock();

    // Algoritmo Bubble Sort
    for (i = 0; i < n; i++) {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            result.comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Trocar os elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                result.movements++;
                swapped = 1;
            }
        }

        // Se nenhuma troca foi feita nesta passagem, o array já está ordenado
        if (swapped == 0) {
            break;
        }
    }

    // Calcular tempo de execução em segundos
    result.execution_time = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

    return result;
}

// Funções auxiliares para o QuickSort
static unsigned long long quick_sort_comparisons = 0;
static unsigned long long quick_sort_movements = 0;

/**
 * Função para particionar o array (QuickSort)
 */
static int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        quick_sort_comparisons++;
        if (arr[j] <= pivot) {
            i++;
            // Trocar arr[i] e arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            quick_sort_movements++;
        }
    }

    // Trocar arr[i+1] e arr[high] (pivô)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    quick_sort_movements++;

    return i + 1;
}

/**
 * Função recursiva do QuickSort
 */
static void quicksort_recursive(int *arr, int low, int high) {
    if (low < high) {
        // Particionar o array
        int pivot_idx = partition(arr, low, high);

        // Ordenar elementos antes e depois da partição
        quicksort_recursive(arr, low, pivot_idx - 1);
        quicksort_recursive(arr, pivot_idx + 1, high);
    }
}

/**
 * Quick Sort (Ordenação Rápida)
 */
SortResult quick_sort(int *arr, int n) {
    SortResult result = {0, 0, 0.0};

    // Reiniciar contadores globais
    quick_sort_comparisons = 0;
    quick_sort_movements = 0;

    // Medir tempo de início
    clock_t start_time = clock();

    // Algoritmo QuickSort
    quicksort_recursive(arr, 0, n - 1);

    // Calcular tempo de execução em segundos
    result.execution_time = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

    // Copiar contadores globais para o resultado
    result.comparisons = quick_sort_comparisons;
    result.movements = quick_sort_movements;

    return result;
}