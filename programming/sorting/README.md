# 📊 Algoritmos de Ordenação em Memória Primária

## 🔍 Introdução

Os algoritmos de ordenação são fundamentais na ciência da computação, transformando dados desordenados em sequências ordenadas, facilitando pesquisas, análises e otimizando outras operações computacionais. Esses algoritmos são essenciais em praticamente todas as aplicações que lidam com dados estruturados.

Este documento explora detalhadamente os principais algoritmos de ordenação, suas implementações, complexidades e casos de uso ideais.

## 📝 Algoritmos de Ordenação

### 1. Algoritmos Simples (O(n²))

#### **Bubble Sort (Método da Bolha)**

- **Funcionamento**: 
  O Bubble Sort é um algoritmo intuitivo que funciona comparando pares adjacentes de elementos e trocando-os se estiverem na ordem errada. A cada passagem completa pelo array, o maior elemento não ordenado "borbulha" para sua posição correta no final do array.

- **Complexidade**: 
  - **Melhor caso**: O(n) - quando o array já está ordenado
  - **Caso médio e pior caso**: O(n²) - quando o array está em ordem inversa

- **Características**: 
  - Simples de entender e implementar
  - Algoritmo estável (mantém a ordem relativa de elementos iguais)
  - Ineficiente para grandes conjuntos de dados
  - Usa comparações e trocas locais
  - Requer apenas O(1) de memória adicional

- **Explicação do código**:

```c
void bubbleSort(int *v, int n) { 
    if (n < 1) return; // Caso base: se o tamanho for menor que 1, retorna
 
    // Percorre o array uma vez, comparando elementos adjacentes
    for (int i = 0; i < n; i++) 
        // Se o elemento atual for maior que o próximo, troca-os
        if (v[i] > v[i+1]) 
            swap(&v[i], &v[i+1]);  
    
    // Chamada recursiva com tamanho reduzido
    // O maior elemento já está na posição correta, então reduzimos o tamanho
    bubbleSort(v, n-1); 
} 
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[5, 3, 8, 4, 2]`:
  
  1. Primeira passagem:
     - Compara 5 e 3: troca → `[3, 5, 8, 4, 2]`
     - Compara 5 e 8: não troca → `[3, 5, 8, 4, 2]`
     - Compara 8 e 4: troca → `[3, 5, 4, 8, 2]`
     - Compara 8 e 2: troca → `[3, 5, 4, 2, 8]`
     
  2. Segunda passagem:
     - Compara 3 e 5: não troca → `[3, 5, 4, 2, 8]`
     - Compara 5 e 4: troca → `[3, 4, 5, 2, 8]`
     - Compara 5 e 2: troca → `[3, 4, 2, 5, 8]`
     
  3. Terceira passagem:
     - Compara 3 e 4: não troca → `[3, 4, 2, 5, 8]`
     - Compara 4 e 2: troca → `[3, 2, 4, 5, 8]`
     
  4. Quarta passagem:
     - Compara 3 e 2: troca → `[2, 3, 4, 5, 8]`
     
  Array ordenado: `[2, 3, 4, 5, 8]`

#### **Selection Sort (Método da Seleção)**

- **Funcionamento**: 
  O Selection Sort divide o array em duas partes: uma parte ordenada (inicialmente vazia) e uma parte não ordenada. A cada iteração, o algoritmo encontra o menor elemento da parte não ordenada e o move para o final da parte ordenada.

- **Complexidade**: 
  - **Todos os casos**: O(n²) - independentemente da distribuição inicial dos dados

- **Características**: 
  - Número de trocas é O(n), sendo eficiente quando as operações de troca são caras
  - Sempre realiza o mesmo número de comparações, independentemente da ordem inicial
  - Não é adaptativo (não se beneficia de ordenação parcial)
  - Não é estável (pode alterar a ordem relativa de elementos iguais)
  - Usa apenas O(1) de memória auxiliar

- **Explicação do código**:

```c
void selectionSort(int *v, int n) { 
    if (n < 1) return; // Caso base: se o tamanho for menor que 1, retorna
 
    int min = v[0]; // Inicialmente, assume o primeiro elemento como mínimo
    int minIndex = 0; // Guarda o índice do elemento mínimo
    
    // Percorre o array para encontrar o menor elemento
    for (int i = 1; i < n; i++) 
        if (v[i] < min) { // Se encontrar um elemento menor
            min = v[i]; // Atualiza o valor mínimo
            minIndex = i; // Atualiza o índice do mínimo
        } 
    
    // Coloca o menor elemento no início do array
    swap(&v[0], &v[minIndex]); 
    
    // Chamada recursiva excluindo o primeiro elemento (que já está ordenado)
    selectionSort(v+1, n-1); 
} 
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[5, 3, 8, 4, 2]`:
  
  1. Primeira iteração:
     - Encontra o menor valor (2) na posição 4
     - Troca com o primeiro elemento: `[2, 3, 8, 4, 5]`
     
  2. Segunda iteração (subarray `[3, 8, 4, 5]`):
     - Encontra o menor valor (3) na posição 0
     - Já está na posição correta: `[2, 3, 8, 4, 5]`
     
  3. Terceira iteração (subarray `[8, 4, 5]`):
     - Encontra o menor valor (4) na posição 1
     - Troca com o primeiro elemento do subarray: `[2, 3, 4, 8, 5]`
     
  4. Quarta iteração (subarray `[8, 5]`):
     - Encontra o menor valor (5) na posição 1
     - Troca com o primeiro elemento do subarray: `[2, 3, 4, 5, 8]`
     
  Array ordenado: `[2, 3, 4, 5, 8]`

#### **Insertion Sort (Método da Inserção)**

- **Funcionamento**: 
  O Insertion Sort constrói a sequência ordenada um elemento por vez. Para cada elemento, o algoritmo o insere na posição correta entre os elementos já ordenados, deslocando os elementos maiores uma posição à direita.

- **Complexidade**: 
  - **Melhor caso**: O(n) - quando o array já está ordenado
  - **Caso médio e pior caso**: O(n²) - quando o array está em ordem inversa

- **Características**: 
  - Extremamente eficiente para arrays pequenos ou quase ordenados
  - Adaptativo (se beneficia de ordenação parcial prévia)
  - Estável (mantém a ordem relativa de elementos iguais)
  - Online (pode processar os dados conforme chegam)
  - Usa apenas O(1) de memória auxiliar

- **Explicação do código**:

```c
void insertionSort(int *v, int n) { 
    if (n < 1) return; // Caso base: se o tamanho for menor que 1, retorna
 
    // O primeiro elemento é considerado ordenado
    // Percorremos a partir do segundo elemento
    for (int i = 1; i < n; i++) {
        int chave = v[i]; // Armazena o elemento atual (chave)
        int j = i - 1;    // Índice do elemento anterior
        
        // Move os elementos do subarray v[0..i-1] que são maiores que a chave
        // uma posição à frente de sua posição atual
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j]; // Desloca o elemento maior para a direita
            j--;             // Move para o próximo elemento à esquerda
        }
        
        v[j + 1] = chave; // Coloca a chave na posição correta
    } 
} 
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[5, 3, 8, 4, 2]`:
  
  1. Começamos com o primeiro elemento (5) considerado ordenado: `[5 | 3, 8, 4, 2]`
  
  2. Inserimos 3:
     - 3 < 5, então movemos 5 uma posição para a direita e inserimos 3 na posição 0
     - `[3, 5 | 8, 4, 2]`
  
  3. Inserimos 8:
     - 8 > 5, então 8 já está na posição correta
     - `[3, 5, 8 | 4, 2]`
  
  4. Inserimos 4:
     - 4 < 8, então movemos 8 uma posição para a direita
     - 4 < 5, então movemos 5 uma posição para a direita
     - 4 > 3, então inserimos 4 após 3
     - `[3, 4, 5, 8 | 2]`
  
  5. Inserimos 2:
     - 2 < 8, movemos 8 uma posição para a direita
     - 2 < 5, movemos 5 uma posição para a direita
     - 2 < 4, movemos 4 uma posição para a direita
     - 2 < 3, movemos 3 uma posição para a direita
     - Inserimos 2 na posição 0
     - `[2, 3, 4, 5, 8]`
  
  Array ordenado: `[2, 3, 4, 5, 8]`

### 2. Algoritmos Intermediários

#### **Shell Sort**

- **Funcionamento**: 
  O Shell Sort é uma extensão do Insertion Sort que permite a comparação e troca de elementos distantes. O algoritmo começa com um "gap" grande e vai reduzindo até chegar a 1, quando se torna um Insertion Sort regular. A diferença é que, ao permitir trocas de elementos distantes, grandes valores próximos ao início do array podem se mover rapidamente para o final, e pequenos valores próximos ao final podem se mover rapidamente para o início.

- **Complexidade**: 
  - **Melhor caso**: O(n log n)
  - **Caso médio**: Depende da sequência de gaps, mas geralmente entre O(n^1.3) e O(n^1.5)
  - **Pior caso**: O(n²)

- **Características**: 
  - Melhor desempenho que outros algoritmos O(n²) na prática
  - Não é estável (pode alterar a ordem relativa de elementos iguais)
  - A escolha da sequência de gaps afeta significativamente o desempenho
  - Usa apenas O(1) de memória auxiliar

- **Explicação do código**:

```c
void shellSort(int *v, int n) {
    if (n < 1) return; // Caso base: se o tamanho for menor que 1, retorna
 
    // Loop externo define o gap e o reduz progressivamente
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Para cada gap, aplica uma variação do Insertion Sort
        for (int i = gap; i < n; i++) {
            // Armazena o valor atual para encontrar sua posição correta
            int temp = v[i];
            int j;
            
            // Move os elementos que são maiores que temp e estão separados
            // por gap posições para uma posição à frente
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            
            // Coloca temp na posição correta
            v[j] = temp;
        }
    }
}
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[9, 8, 3, 7, 5, 6, 4, 1]` com a sequência de gaps [4, 2, 1]:
  
  1. Gap = 4:
     - Compara e ordena elementos distantes 4 posições:
     - Subarray 1: `[9, _, _, _, 5, _, _, _]` → `[5, _, _, _, 9, _, _, _]`
     - Subarray 2: `[_, 8, _, _, _, 6, _, _]` → `[_, 6, _, _, _, 8, _, _]`
     - Subarray 3: `[_, _, 3, _, _, _, 4, _]` → `[_, _, 3, _, _, _, 4, _]`
     - Subarray 4: `[_, _, _, 7, _, _, _, 1]` → `[_, _, _, 1, _, _, _, 7]`
     - Array após gap 4: `[5, 6, 3, 1, 9, 8, 4, 7]`
  
  2. Gap = 2:
     - Compara e ordena elementos distantes 2 posições:
     - Subarray 1: `[5, _, 3, _, 9, _, 4, _]` → `[3, _, 5, _, 4, _, 9, _]`
     - Subarray 2: `[_, 6, _, 1, _, 8, _, 7]` → `[_, 1, _, 6, _, 7, _, 8]`
     - Array após gap 2: `[3, 1, 5, 6, 4, 7, 9, 8]`
  
  3. Gap = 1 (Insertion Sort regular):
     - Ordena todo o array com gap 1
     - Array final: `[1, 3, 4, 5, 6, 7, 8, 9]`

### 3. Algoritmos Eficientes (O(n log n))

#### **Quick Sort**

- **Funcionamento**: 
  O Quick Sort é um algoritmo de divisão e conquista que escolhe um elemento (pivô) e particiona o array em dois subarrays: elementos menores que o pivô e elementos maiores que o pivô. Em seguida, os subarrays são ordenados recursivamente. A eficiência do algoritmo depende fortemente da escolha do pivô.

- **Complexidade**: 
  - **Melhor caso e caso médio**: O(n log n)
  - **Pior caso**: O(n²) - quando o pivô é sempre o menor ou maior elemento

- **Características**: 
  - Geralmente o mais rápido na prática entre os algoritmos O(n log n)
  - In-place (requer apenas O(log n) memória auxiliar para a pilha de recursão)
  - Não é estável (pode alterar a ordem relativa de elementos iguais)
  - A eficiência depende da escolha do pivô
  - Altamente paralelizável

- **Explicação do código**:

```c
void quickSort(int *v, int n) { 
    if (n <= 1) return; // Caso base: arrays de tamanho 0 ou 1 já estão ordenados
 
    // Escolhe o pivô como o elemento do meio
    int pivot = v[n/2]; 
    
    // Índices para percorrer o array da esquerda para a direita (i)
    // e da direita para a esquerda (j)
    int i = 0, j = n - 1; 
    
    // Particiona o array
    while (i <= j) { 
        // Encontra um elemento maior ou igual ao pivô do lado esquerdo
        while (v[i] < pivot) i++; 
        
        // Encontra um elemento menor ou igual ao pivô do lado direito
        while (v[j] > pivot) j--; 
        
        // Se os índices não se cruzaram, troca os elementos
        if (i <= j) { 
            swap(&v[i], &v[j]); // Troca os elementos
            i++; // Avança o índice da esquerda
            j--; // Recua o índice da direita
        } 
    } 
    
    // Ordena recursivamente os subarrays à esquerda e à direita do pivô
    quickSort(v, j + 1);     // Subarray à esquerda do pivô
    quickSort(v + i, n - i); // Subarray à direita do pivô
} 
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[7, 2, 1, 6, 8, 5, 3, 4]`:
  
  1. Escolhe 5 como pivô (elemento do meio)
  
  2. Particionamento:
     - i começa em 0, j começa em 7
     - v[0] = 7 > 5 (pivô), então i permanece em 0
     - v[7] = 4 < 5 (pivô), então j permanece em 7
     - Troca v[0] com v[7]: `[4, 2, 1, 6, 8, 5, 3, 7]`
     - i = 1, j = 6
     - v[1] = 2 < 5, então i = 2
     - v[6] = 3 < 5, então j = 5
     - v[2] = 1 < 5, então i = 3
     - v[5] = 5 = 5, então j = 4
     - v[3] = 6 > 5, i permanece em 3
     - v[4] = 8 > 5, j permanece em 4
     - Troca v[3] com v[4]: `[4, 2, 1, 8, 6, 5, 3, 7]`
     - i = 4, j = 3 (índices se cruzaram, particionamento concluído)
     
  3. Agora, recursivamente ordenamos:
     - Subarray à esquerda: `[4, 2, 1]` → `[1, 2, 4]`
     - Subarray à direita: `[8, 6, 5, 3, 7]` → `[3, 5, 6, 7, 8]`
     
  4. Array ordenado: `[1, 2, 4, 3, 5, 6, 7, 8]`
  
  5. Continuamos as chamadas recursivas até obter o array final ordenado: `[1, 2, 3, 4, 5, 6, 7, 8]`

#### **Merge Sort**

- **Funcionamento**: 
  O Merge Sort é um algoritmo de divisão e conquista que divide o array em duas metades, ordena cada metade recursivamente e, em seguida, mescla as duas metades ordenadas. O algoritmo é muito eficiente e garante complexidade O(n log n) em todos os casos.

- **Complexidade**: 
  - **Todos os casos**: O(n log n)

- **Características**: 
  - Estável (mantém a ordem relativa de elementos iguais)
  - Desempenho previsível (sempre O(n log n))
  - Requer memória auxiliar O(n)
  - Altamente paralelizável
  - Eficiente para grandes conjuntos de dados

- **Explicação do código**:

```c
// Função para mesclar duas sublistas ordenadas
void merge(int *v, int left, int mid, int right) { 
    // Calcula o tamanho das duas sublistas
    int n1 = mid - left + 1; // Tamanho da sublista esquerda
    int n2 = right - mid;    // Tamanho da sublista direita
 
    // Cria arrays temporários para armazenar as sublistas
    int L[n1], R[n2]; 
 
    // Copia os elementos para os arrays temporários
    for (int i = 0; i < n1; i++) 
        L[i] = v[left + i]; // Copia a sublista esquerda
    
    for (int j = 0; j < n2; j++) 
        R[j] = v[mid + 1 + j]; // Copia a sublista direita
 
    // Índices para percorrer os arrays
    int i = 0;      // Índice para o array L (esquerda)
    int j = 0;      // Índice para o array R (direita)
    int k = left;   // Índice para o array original v
 
    // Mescla os dois arrays em ordem crescente
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { // Se o elemento de L for menor ou igual
            v[k] = L[i]; // Coloca o elemento de L no array original
            i++; 
        } else { 
            v[k] = R[j]; // Coloca o elemento de R no array original
            j++; 
        } 
        k++; 
    } 
 
    // Copia os elementos restantes de L, se houver
    while (i < n1) { 
        v[k] = L[i]; 
        i++; 
        k++; 
    } 
 
    // Copia os elementos restantes de R, se houver
    while (j < n2) { 
        v[k] = R[j]; 
        j++; 
        k++; 
    } 
}

// Função principal do Merge Sort
void mergeSort(int *v, int left, int right) {
    if (left < right) {
        // Encontra o ponto médio
        int mid = left + (right - left) / 2;
        
        // Ordena recursivamente as duas metades
        mergeSort(v, left, mid);       // Ordena a metade esquerda
        mergeSort(v, mid + 1, right);  // Ordena a metade direita
        
        // Mescla as duas metades ordenadas
        merge(v, left, mid, right);
    }
}
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[8, 3, 5, 1, 9, 6, 2]`:
  
  1. Dividimos o array ao meio:
     - Metade esquerda: `[8, 3, 5]`
     - Metade direita: `[1, 9, 6, 2]`
  
  2. Ordenamos recursivamente a metade esquerda:
     - Dividimos: `[8]` e `[3, 5]`
     - Ordenamos `[3, 5]` → `[3, 5]`
     - Mesclamos: `[8]` e `[3, 5]` → `[3, 5, 8]`
  
  3. Ordenamos recursivamente a metade direita:
     - Dividimos: `[1, 9]` e `[6, 2]`
     - Ordenamos `[1, 9]` → `[1, 9]`
     - Ordenamos `[6, 2]` → `[2, 6]`
     - Mesclamos: `[1, 9]` e `[2, 6]` → `[1, 2, 6, 9]`
  
  4. Mesclamos as duas metades ordenadas:
     - Mesclamos: `[3, 5, 8]` e `[1, 2, 6, 9]` → `[1, 2, 3, 5, 6, 8, 9]`

#### **Heap Sort**

- **Funcionamento**: 
  O Heap Sort utiliza uma estrutura de dados chamada heap (geralmente um heap máximo) para ordenar os elementos. O algoritmo constrói um heap a partir do array e, em seguida, repetidamente extrai o elemento máximo do heap, reconstruindo o heap a cada extração.

- **Complexidade**: 
  - **Todos os casos**: O(n log n)

- **Características**: 
  - In-place (usa apenas O(1) de memória auxiliar)
  - Não é estável (pode alterar a ordem relativa de elementos iguais)
  - Desempenho consistente em todos os casos
  - Menos eficiente na prática que Quick Sort, mas com garantia de O(n log n)

- **Implementação e explicação do código**:

```c
// Função para manter a propriedade do heap
void heapify(int *v, int n, int i) {
    int largest = i;      // Inicializa o maior como raiz
    int left = 2 * i + 1; // Filho esquerdo
    int right = 2 * i + 2; // Filho direito
    
    // Se o filho esquerdo é maior que a raiz
    if (left < n && v[left] > v[largest])
        largest = left;
    
    // Se o filho direito é maior que o maior até agora
    if (right < n && v[right] > v[largest])
        largest = right;
    
    // Se o maior não é a raiz
    if (largest != i) {
        swap(&v[i], &v[largest]); // Troca a raiz com o maior
        
        // Heapify recursivamente a subárvore afetada
        heapify(v, n, largest);
    }
}

// Função principal do Heap Sort
void heapSort(int *v, int n) {
    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
    
    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (máximo) para o final
        swap(&v[0], &v[i]);
        
        // Chama heapify na heap reduzida
        heapify(v, i, 0);
    }
}
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[4, 10, 3, 5, 1]`:
  
  1. Construção do heap máximo:
     - Começa com o array como uma árvore binária completa:
      ```
           4
         /   \
        10    3
       / \
      5   1
      ```
     
     - Aplica heapify aos nós não-folha (de baixo para cima):
       - heapify(2): Nó 3 não tem filhos, permanece igual
       - heapify(1): Nó 10 tem filhos 5 e 1, 10 > 5 e 10 > 1, permanece igual
       - heapify(0): Nó 4 tem filhos 10 e 3, 4 < 10, troca 4 e 10
       
     - Após construir o heap, temos:
       ```
            10
          /    \
          5      3
        / \
        4   1
       ```
       
     - Array representando o heap: `[10, 5, 3, 4, 1]`
  
  2. Extração dos elementos:
     - Troca 10 (raiz) com 1 (último elemento): `[1, 5, 3, 4, 10]`
     - Heapify na heap reduzida (excluindo 10): `[5, 4, 3, 1, 10]`
     
     - Troca 5 (raiz) com 1 (último elemento): `[1, 4, 3, 5, 10]`
     - Heapify na heap reduzida: `[4, 1, 3, 5, 10]`
     
     - Troca 4 (raiz) com 3 (último elemento): `[3, 1, 4, 5, 10]`
     - Heapify na heap reduzida: `[3, 1, 4, 5, 10]`
     
     - Troca 3 (raiz) com 1 (último elemento): `[1, 3, 4, 5, 10]`
     
  3. Array ordenado: `[1, 3, 4, 5, 10]`

### 4. Algoritmos Lineares (O(n))

#### **Counting Sort**

- **Funcionamento**: 
  O Counting Sort conta o número de ocorrências de cada elemento e usa essas contagens para determinar a posição correta de cada elemento no array ordenado. É eficiente quando o intervalo de valores possíveis não é muito maior que o tamanho do array.

- **Complexidade**: 
  - **Todos os casos**: O(n + k), onde k é o tamanho do intervalo de valores

- **Características**: 
  - Não é baseado em comparações
  - Estável (mantém a ordem relativa de elementos iguais)
  - Eficiente apenas para intervalos pequenos de valores inteiros
  - Requer memória auxiliar O(n + k)

- **Implementação e explicação do código**:

```c
// Função para encontrar o valor máximo no array
int findMax(int *v, int n) {
    int max = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

// Função principal do Counting Sort
void countingSort(int *v, int n) {
    // Encontra o valor máximo para determinar o tamanho do array de contagem
    int max = findMax(v, n);
    
    // Cria um array de contagem com tamanho max+1
    // (índices de 0 a max)
    int *count = (int *)malloc((max + 1) * sizeof(int));
    
    // Inicializa o array de contagem com zeros
    for (int i = 0; i <= max; i++)
        count[i] = 0;
    
    // Conta a ocorrência de cada elemento
    for (int i = 0; i < n; i++)
        count[v[i]]++;
    
    // Atualiza o array de contagem para conter as posições reais
    // dos elementos no array de saída
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    
    // Cria um array de saída
    int *output = (int *)malloc(n * sizeof(int));
    
    // Constrói o array de saída
    // Percorre o array original de trás para frente para
    // garantir a estabilidade do algoritmo
    for (int i = n - 1; i >= 0; i--) {
        output[count[v[i]] - 1] = v[i];
        count[v[i]]--;
    }
    
    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++)
        v[i] = output[i];
    
    // Libera a memória alocada
    free(count);
    free(output);
}
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[4, 2, 2, 8, 3, 3, 1]`:
  
  1. Encontra o valor máximo: 8
  
  2. Cria um array de contagem de tamanho 9 (índices 0 a 8):
     - count = `[0, 0, 0, 0, 0, 0, 0, 0, 0]`
  
  3. Conta a ocorrência de cada elemento:
     - count = `[0, 1, 2, 2, 1, 0, 0, 0, 1]`
     - (0 ocorre 0 vezes, 1 ocorre 1 vez, 2 ocorre 2 vezes, etc.)
  
  4. Atualiza o array de contagem para conter as posições finais:
     - count = `[0, 1, 3, 5, 6, 6, 6, 6, 7]`
  
  5. Constrói o array de saída:
     - Para o último elemento (1): posição = count[1] - 1 = 0
       output = `[1, _, _, _, _, _, _]`
       count[1] = 0
     
     - Para o penúltimo elemento (3): posição = count[3] - 1 = 4
       output = `[1, _, _, _, 3, _, _]`
       count[3] = 4
     
     - E assim por diante...
     - output final = `[1, 2, 2, 3, 3, 4, 8]`
  
  6. Copia o array de saída para o array original:
     - Array ordenado: `[1, 2, 2, 3, 3, 4, 8]`

#### **Radix Sort**

- **Funcionamento**: 
  O Radix Sort ordena os elementos processando-os dígito por dígito, começando pelo dígito menos significativo (LSD) ou pelo mais significativo (MSD). Para cada dígito, utiliza um algoritmo de ordenação estável, geralmente o Counting Sort.

- **Complexidade**: 
  - **Todos os casos**: O(d(n + k)), onde d é o número de dígitos e k é o intervalo de valores por dígito

- **Características**: 
  - Não é baseado em comparações
  - Estável (mantém a ordem relativa de elementos iguais)
  - Eficiente para números com quantidade limitada de dígitos ou strings
  - Requer memória auxiliar O(n + k)

- **Implementação e explicação do código**:

```c
// Função para obter o dígito na posição exp de um número
int getDigit(int num, int exp) {
    return (num / exp) % 10;
}

// Counting Sort modificado para ordenar por um dígito específico
void countingSortByDigit(int *v, int n, int exp) {
    int output[n];
    int count[10] = {0}; // Dígitos de 0 a 9
    
    // Conta a ocorrência de cada dígito
    for (int i = 0; i < n; i++)
        count[getDigit(v[i], exp)]++;
    
    // Atualiza o array de contagem para conter as posições reais
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(v[i], exp);
        output[count[digit] - 1] = v[i];
        count[digit]--;
    }
    
    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++)
        v[i] = output[i];
}

// Função para encontrar o valor máximo no array
int findMax(int *v, int n) {
    int max = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}

// Função principal do Radix Sort
void radixSort(int *v, int n) {
    // Encontra o valor máximo para determinar o número de dígitos
    int max = findMax(v, n);
    
    // Faz o Counting Sort para cada dígito, começando pelo menos significativo
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortByDigit(v, n, exp);
}
```

- **Exemplo de execução**:
  
  Vamos ordenar o array `[170, 45, 75, 90, 802, 24, 2, 66]`:
  
  1. Encontra o valor máximo: 802 (3 dígitos)
  
  2. Ordena pelo dígito menos significativo (unidades):
     - Analisa o dígito das unidades: `[170, 45, 75, 90, 802, 24, 2, 66]` → `[0, 5, 5, 0, 2, 4, 2, 6]`
     - Após ordenar: `[170, 90, 802, 2, 24, 45, 75, 66]`
  
  3. Ordena pelo dígito das dezenas:
     - Analisa o dígito das dezenas: `[170, 90, 802, 2, 24, 45, 75, 66]` → `[7, 9, 0, 0, 2, 4, 7, 6]`
     - Após ordenar: `[802, 2, 24, 45, 66, 170, 75, 90]`
  
  4. Ordena pelo dígito das centenas:
     - Analisa o dígito das centenas: `[802, 2, 24, 45, 66, 170, 75, 90]` → `[8, 0, 0, 0, 0, 1, 0, 0]`
     - Após ordenar: `[2, 24, 45, 66, 75, 90, 170, 802]`
  
  5. Array ordenado: `[2, 24, 45, 66, 75, 90, 170, 802]`

## 📈 Análise de Complexidade

### Notações Assintóticas
- **Big O (O)**: Limite superior - pior caso. Representa o limite máximo de crescimento de um algoritmo.
- **Big Omega (Ω)**: Limite inferior - melhor caso. Representa o limite mínimo de crescimento.
- **Big Theta (Θ)**: Limite ajustado - caso médio. Representa o crescimento exato quando os limites superior e inferior coincidem.

### Tipos de Análise
1. **Melhor Caso**: Cenário mais favorável, como um array já ordenado para o Insertion Sort, resultando em O(n).
2. **Caso Médio**: Comportamento esperado para uma entrada típica ou aleatória.
3. **Pior Caso**: Cenário mais desfavorável, como um array em ordem inversa para o Quick Sort, resultando em O(n²).

### Comparação de Complexidades

| Algoritmo | Melhor Caso | Caso Médio | Pior Caso | Espaço | Estável |
|-----------|-------------|------------|-----------|--------|---------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Sim |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | Não |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Sim |
| Shell Sort | O(n log n) | O(n^1.3) | O(n²) | O(1) | Não |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | Não |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Sim |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | Não |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(n+k) | Sim |
| Radix Sort | O(d(n+k)) | O(d(n+k)) | O(d(n+k)) | O(n+k) | Sim |

## 🎯 Escolha do Algoritmo Ideal

### Quando usar cada algoritmo:

- **Insertion Sort**: 
  - Conjuntos pequenos (n < 50)
  - Dados quase ordenados
  - Quando novas entradas chegam continuamente (online)
  - Como fase final em algoritmos híbridos

- **Quick Sort**: 
  - Melhor opção geral na prática
  - Quando espaço auxiliar é limitado
  - Quando estabilidade não é necessária
  - Boa escolha para arrays de tamanho médio a grande

- **Merge Sort**: 
  - Quando estabilidade é importante
  - Quando garantia de O(n log n) é essencial
  - Em ordenação externa (grandes volumes)
  - Quando há memória disponível

- **Heap Sort**: 
  - Quando garantia de desempenho é crítica
  - Espaço limitado mas O(n log n) necessário
  - Quando pior caso O(n log n) é requisito

- **Counting/Radix Sort**: 
  - Conjunto de dados com faixa limitada de valores
  - Quando valores são inteiros ou strings
  - Grande volume de dados em faixa pequena
  - Quando a velocidade é mais importante que o uso de memória

## 🧠 Conceitos Importantes

### 1. Estabilidade
- Um algoritmo é **estável** quando mantém a ordem relativa de elementos com valores iguais
- Importante em ordenações multi-campo (ex: ordenar por preço mantendo ordem alfabética)
- Algoritmos estáveis: Bubble Sort, Insertion Sort, Merge Sort, Counting Sort, Radix Sort
- Algoritmos não estáveis: Selection Sort, Shell Sort, Quick Sort, Heap Sort

### 2. In-Place vs. Out-of-Place
- **In-Place**: Usa memória auxiliar constante O(1)
  - Exemplos: Bubble Sort, Selection Sort, Insertion Sort, Shell Sort, Heap Sort
  - O Quick Sort é considerado In-Place mesmo usando O(log n) para a pilha de recursão
- **Out-of-Place**: Requer memória auxiliar significativa
  - Exemplos: Merge Sort, Counting Sort, Radix Sort

### 3. Adaptatividade
- Um algoritmo é **adaptativo** quando se beneficia de ordenação parcial prévia
- Insertion Sort é extremamente adaptativo (O(n) para arrays quase ordenados)
- Algoritmos não adaptativos: Selection Sort, Heap Sort
- Parcialmente adaptativos: Bubble Sort, Quick Sort

### 4. Ordenação Parcial
- Muitas aplicações precisam apenas dos k menores elementos
- Heap parcial pode resolver em O(n + k log n)
- Aplicações: sistemas de recomendação, top-k consultas

### 5. Ordenação Paralela
- Algoritmos como Merge Sort e Quick Sort podem ser paralelizados
- Aproveitam múltiplos núcleos/threads para acelerar o processamento
- Importante em sistemas distribuídos e computação de alto desempenho

## 💡 Dicas Práticas

1. Para conjuntos pequenos, algoritmos simples como Insertion Sort frequentemente superam algoritmos teoricamente mais eficientes devido ao baixo overhead

2. Algoritmos híbridos combinam diferentes abordagens para explorar o melhor de cada um:
   - Quick Sort + Insertion Sort para partições pequenas
   - Intro Sort (Quick Sort + Heap Sort) para garantir O(n log n)
   - Tim Sort (Merge Sort + Insertion Sort) para dados reais

3. A escolha do pivô no Quick Sort é crucial para evitar o pior caso:
   - Mediana de três: primeiro, meio e último elemento
   - Escolha aleatória
   - Sample Sort: amostra de elementos para escolher um bom pivô

4. Na prática, bibliotecas de linguagens utilizam:
   - Java: TimSort (híbrido Merge + Insertion)
   - C++: IntroSort (híbrido Quick + Heap + Insertion)
   - Python: TimSort
   - JavaScript: Implementações específicas de cada navegador, geralmente baseadas em Quick Sort

5. Em bancos de dados, índices ordenados geralmente utilizam estruturas de árvore B ou B+ em vez de arrays ordenados, otimizando para operações de busca, inserção e exclusão

6. Em aplicações de Big Data, algoritmos de ordenação externa e distribuída como External Merge Sort são preferíveis

---

## 🔄 Implementações Avançadas e Otimizações

### 1. Otimizações do Quick Sort
- **Escolha do pivô inteligente**:
  ```c
  // Escolha do pivô usando mediana de três
  int choosePivot(int *v, int left, int right) {
      int mid = left + (right - left) / 2;
      
      // Ordena os três elementos: v[left], v[mid], v[right]
      if (v[left] > v[mid])
          swap(&v[left], &v[mid]);
      if (v[mid] > v[right])
          swap(&v[mid], &v[right]);
      if (v[left] > v[mid])
          swap(&v[left], &v[mid]);
          
      // Retorna o valor do meio
      return v[mid];
  }
  ```

- **Particionamento de três vias**:
  ```c
  // Particiona o array em três partes: menor, igual e maior que o pivô
  void threeWayPartition(int *v, int left, int right, int *lt, int *gt) {
      int pivot = v[left];
      int i = left + 1;
      *lt = left;
      *gt = right;
      
      while (i <= *gt) {
          if (v[i] < pivot) {
              swap(&v[i], &v[*lt]);
              (*lt)++;
              i++;
          } else if (v[i] > pivot) {
              swap(&v[i], &v[*gt]);
              (*gt)--;
          } else {
              i++;
          }
      }
  }
  ```

### 2. Merge Sort Iterativo
```c
// Versão iterativa do Merge Sort, evitando recursão excessiva
void iterativeMergeSort(int *v, int n) {
    // Tamanho atual das sublistas a serem mescladas
    // Começa com 1 e duplica a cada iteração
    for (int curr_size = 1; curr_size < n; curr_size = 2 * curr_size) {
        // Ponto de início de cada sublista
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // Encontra o ponto médio e o ponto final
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            
            // Mescla as sublistas v[left_start...mid] e v[mid+1...right_end]
            merge(v, left_start, mid, right_end);
        }
    }
}
```

### 3. Otimizações do Heap Sort
```c
// Versão do Heap Sort com heap binário mais eficiente
void optimizedHeapSort(int *v, int n) {
    // Constrói o heap de baixo para cima
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(v, i, n);
    
    // Extrai os elementos um por um
    for (int i = n - 1; i > 0; i--) {
        swap(&v[0], &v[i]);
        siftDown(v, 0, i);
    }
}

// Versão otimizada da função heapify
void siftDown(int *v, int root, int n) {
    int temp = v[root];
    int child;
    
    for (; 2 * root + 1 < n; root = child) {
        child = 2 * root + 1;
        
        // Escolhe o maior filho
        if (child + 1 < n && v[child] < v[child + 1])
            child++;
        
        // Se o filho for maior que o pai, move o filho para cima
        if (temp < v[child])
            v[root] = v[child];
        else
            break;
    }
    
    v[root] = temp;
}
```

### 4. Implementação do IntroSort (híbrido de Quick Sort, Heap Sort e Insertion Sort)
```c
// Determina a profundidade máxima antes de mudar para Heap Sort
int maxDepth(int n) {
    return 2 * (int)floor(log2(n));
}

// Função principal do IntroSort
void introSort(int *v, int n) {
    int depthLimit = maxDepth(n);
    introSortUtil(v, 0, n - 1, depthLimit);
}

// Função utilitária para o IntroSort
void introSortUtil(int *v, int begin, int end, int depthLimit) {
    // Se o array for pequeno, use Insertion Sort
    if (end - begin < 16) {
        insertionSort(v + begin, end - begin + 1);
        return;
    }
    
    // Se a profundidade máxima for zero, use Heap Sort
    if (depthLimit == 0) {
        heapSort(v + begin, end - begin + 1);
        return;
    }
    
    // Caso contrário, use Quick Sort
    int pivot = partition(v, begin, end);
    introSortUtil(v, begin, pivot - 1, depthLimit - 1);
    introSortUtil(v, pivot + 1, end, depthLimit - 1);
}
```