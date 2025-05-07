# 📚 Estruturas de Dados Flexíveis - Guia Completo

## 📋 Sumário
- [Introdução](#introdução)
- [1. Listas Simplesmente Encadeadas](#1-listas-simplesmente-encadeadas)
- [2. Listas Duplamente Encadeadas](#2-listas-duplamente-encadeadas)
- [3. Matrizes Esparsas](#3-matrizes-esparsas)
- [4. Comparação Entre Estruturas](#4-comparação-entre-estruturas)
- [5. Desafios Resolvidos](#5-desafios-resolvidos)

## Introdução

As estruturas de dados flexíveis são fundamentais na ciência da computação por permitirem alocação dinâmica de memória, adaptando-se ao volume de dados durante a execução do programa. Diferentemente das estruturas estáticas (como arrays), as estruturas flexíveis utilizam ponteiros para estabelecer relações entre seus elementos, permitindo crescimento e redução conforme necessário.

### Características principais:
- Alocação dinâmica de memória
- Uso de ponteiros para referenciar elementos
- Tamanho variável durante a execução
- Flexibilidade na inserção e remoção de elementos

## 1. Listas Simplesmente Encadeadas

### 1.1 Conceito

Uma lista simplesmente encadeada é uma coleção de nós onde cada nó contém:
- Um valor (ou dado)
- Um ponteiro para o próximo nó da sequência

O último nó aponta para NULL, indicando o fim da lista.

### 1.2 Estrutura de um Nó

```c
// Em C
typedef struct No {
    int valor;
    struct No* prox;
} No;
```

```java
// Em Java
class No {
    int valor;
    No prox;
    
    public No(int valor) {
        this.valor = valor;
        this.prox = null;
    }
}
```

### 1.3 Representação Visual

```
head → [valor|prox] → [valor|prox] → [valor|prox] → [valor|NULL]
```

### 1.4 Operações Básicas

#### 1.4.1 Criação da lista

```c
// Em C
No* criarLista() {
    return NULL;  // Lista vazia inicialmente
}
```

```java
// Em Java
class ListaSimples {
    No head;
    
    public ListaSimples() {
        this.head = null;  // Lista vazia inicialmente
    }
}
```

#### 1.4.2 Inserção no início

```c
// Em C
No* inserirInicio(No* head, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return head;  // Falha na alocação
    
    novo->valor = valor;
    novo->prox = head;
    return novo;  // Novo head
}
```

```java
// Em Java
void inserirInicio(int valor) {
    No novo = new No(valor);
    novo.prox = head;
    head = novo;
}
```

#### 1.4.3 Inserção no final

```c
// Em C
No* inserirFinal(No* head, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return head;  // Falha na alocação
    
    novo->valor = valor;
    novo->prox = NULL;
    
    if (head == NULL) return novo;
    
    No* atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    atual->prox = novo;
    return head;
}
```

```java
// Em Java
void inserirFinal(int valor) {
    No novo = new No(valor);
    
    if (head == null) {
        head = novo;
        return;
    }
    
    No atual = head;
    while (atual.prox != null) {
        atual = atual.prox;
    }
    
    atual.prox = novo;
}
```

#### 1.4.4 Busca

```c
// Em C
No* buscar(No* head, int valor) {
    No* atual = head;
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;  // Encontrou
        }
        atual = atual->prox;
    }
    
    return NULL;  // Não encontrou
}
```

```java
// Em Java
No buscar(int valor) {
    No atual = head;
    
    while (atual != null) {
        if (atual.valor == valor) {
            return atual;  // Encontrou
        }
        atual = atual.prox;
    }
    
    return null;  // Não encontrou
}
```

#### 1.4.5 Remoção

```c
// Em C
No* remover(No* head, int valor) {
    if (head == NULL) return NULL;
    
    // Caso especial: remover o primeiro nó
    if (head->valor == valor) {
        No* temp = head;
        head = head->prox;
        free(temp);
        return head;
    }
    
    No* atual = head;
    while (atual->prox != NULL && atual->prox->valor != valor) {
        atual = atual->prox;
    }
    
    if (atual->prox != NULL) {
        No* temp = atual->prox;
        atual->prox = atual->prox->prox;
        free(temp);
    }
    
    return head;
}
```

```java
// Em Java
void remover(int valor) {
    if (head == null) return;
    
    // Caso especial: remover o primeiro nó
    if (head.valor == valor) {
        head = head.prox;
        return;
    }
    
    No atual = head;
    while (atual.prox != null && atual.prox.valor != valor) {
        atual = atual.prox;
    }
    
    if (atual.prox != null) {
        atual.prox = atual.prox.prox;
    }
}
```

### 1.5 Complexidade

| Operação | Complexidade | Observação |
|----------|--------------|------------|
| Inserção no início | O(1) | Constante |
| Inserção no final | O(n) | Linear, percorre toda a lista |
| Busca | O(n) | Linear, pior caso percorre toda a lista |
| Remoção | O(n) | Linear, pior caso percorre n-1 elementos |
| Acesso por índice | O(n) | Linear, precisa percorrer até o índice |

### 1.6 Vantagens e Desvantagens

**Vantagens:**
- Inserção e remoção no início em tempo constante O(1)
- Tamanho dinâmico
- Implementação simples

**Desvantagens:**
- Acesso sequencial (não permite acesso direto a elementos)
- Operações no final requerem percorrer toda a lista
- Não permite navegação reversa

## 2. Listas Duplamente Encadeadas

### 2.1 Conceito

Uma lista duplamente encadeada é uma extensão da lista simplesmente encadeada onde cada nó mantém:
- Um valor (ou dado)
- Um ponteiro para o próximo nó (prox)
- Um ponteiro para o nó anterior (ant)

Esta estrutura permite navegação bidirecional.

### 2.2 Estrutura de um Nó

```c
// Em C
typedef struct NoD {
    int valor;
    struct NoD* prox;
    struct NoD* ant;
} NoD;
```

```java
// Em Java
class NoD {
    int valor;
    NoD prox;
    NoD ant;
    
    public NoD(int valor) {
        this.valor = valor;
        this.prox = null;
        this.ant = null;
    }
}
```

### 2.3 Representação Visual

```
NULL ← [ant|valor|prox] ⟷ [ant|valor|prox] ⟷ [ant|valor|prox] → NULL
       ↑
      head
```

### 2.4 Operações Básicas

#### 2.4.1 Criação da lista

```c
// Em C
NoD* criarListaDupla() {
    return NULL;  // Lista vazia inicialmente
}
```

```java
// Em Java
class ListaDupla {
    NoD head;
    NoD tail;  // Opcional, mas útil para inserção no final em O(1)
    
    public ListaDupla() {
        this.head = null;
        this.tail = null;
    }
}
```

#### 2.4.2 Inserção no início

```c
// Em C
NoD* inserirInicioDupla(NoD* head, int valor) {
    NoD* novo = (NoD*) malloc(sizeof(NoD));
    if (novo == NULL) return head;  // Falha na alocação
    
    novo->valor = valor;
    novo->prox = head;
    novo->ant = NULL;
    
    if (head != NULL) {
        head->ant = novo;
    }
    
    return novo;  // Novo head
}
```

```java
// Em Java
void inserirInicio(int valor) {
    NoD novo = new NoD(valor);
    
    if (head == null) {
        head = novo;
        tail = novo;
        return;
    }
    
    novo.prox = head;
    head.ant = novo;
    head = novo;
}
```

#### 2.4.3 Inserção no final

```c
// Em C
NoD* inserirFinalDupla(NoD* head, int valor) {
    NoD* novo = (NoD*) malloc(sizeof(NoD));
    if (novo == NULL) return head;  // Falha na alocação
    
    novo->valor = valor;
    novo->prox = NULL;
    
    if (head == NULL) {
        novo->ant = NULL;
        return novo;
    }
    
    NoD* atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    atual->prox = novo;
    novo->ant = atual;
    
    return head;
}
```

```java
// Em Java
void inserirFinal(int valor) {
    NoD novo = new NoD(valor);
    
    if (head == null) {
        head = novo;
        tail = novo;
        return;
    }
    
    novo.ant = tail;
    tail.prox = novo;
    tail = novo;
}
```

#### 2.4.4 Busca

```c
// Em C
NoD* buscarDupla(NoD* head, int valor) {
    NoD* atual = head;
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;  // Encontrou
        }
        atual = atual->prox;
    }
    
    return NULL;  // Não encontrou
}
```

```java
// Em Java
NoD buscar(int valor) {
    NoD atual = head;
    
    while (atual != null) {
        if (atual.valor == valor) {
            return atual;  // Encontrou
        }
        atual = atual.prox;
    }
    
    return null;  // Não encontrou
}
```

#### 2.4.5 Remoção

```c
// Em C
NoD* removerDupla(NoD* head, int valor) {
    if (head == NULL) return NULL;
    
    NoD* atual = head;
    
    // Busca o nó a ser removido
    while (atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }
    
    if (atual == NULL) return head;  // Não encontrou
    
    // Ajusta os ponteiros do nó anterior
    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    } else {
        head = atual->prox;  // Removendo o head
    }
    
    // Ajusta os ponteiros do nó seguinte
    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }
    
    free(atual);
    return head;
}
```

```java
// Em Java
void remover(int valor) {
    if (head == null) return;
    
    NoD atual = head;
    
    // Busca o nó a ser removido
    while (atual != null && atual.valor != valor) {
        atual = atual.prox;
    }
    
    if (atual == null) return;  // Não encontrou
    
    // Ajusta os ponteiros do nó anterior
    if (atual.ant != null) {
        atual.ant.prox = atual.prox;
    } else {
        head = atual.prox;  // Removendo o head
    }
    
    // Ajusta os ponteiros do nó seguinte
    if (atual.prox != null) {
        atual.prox.ant = atual.ant;
    } else {
        tail = atual.ant;  // Removendo o tail
    }
}
```

### 2.5 Complexidade

| Operação | Complexidade | Observação |
|----------|--------------|------------|
| Inserção no início | O(1) | Constante |
| Inserção no final (com tail) | O(1) | Constante usando ponteiro para o último nó |
| Inserção no final (sem tail) | O(n) | Linear, percorre toda a lista |
| Busca | O(n) | Linear, pior caso percorre toda a lista |
| Remoção (com nó conhecido) | O(1) | Constante se já temos referência ao nó |
| Remoção (por valor) | O(n) | Linear para encontrar o nó |
| Acesso por índice | O(n) | Linear, precisa percorrer até o índice |

### 2.6 Vantagens e Desvantagens

**Vantagens:**
- Navegação bidirecional (para frente e para trás)
- Remoção de um nó em O(1) quando já temos referência ao nó
- Inserção e remoção no final em O(1) quando mantemos ponteiro para o último nó

**Desvantagens:**
- Maior consumo de memória (ponteiro adicional)
- Operações mais complexas devido aos ponteiros duplos
- Acesso ainda é sequencial (não permite acesso direto a elementos por índice)

## 3. Matrizes Esparsas

### 3.1 Conceito

Uma matriz esparsa é uma estrutura de dados otimizada para armazenar matrizes com muitos elementos vazios ou nulos. Em vez de armazenar todos os elementos (inclusive os nulos), armazenamos apenas os elementos não-nulos junto com suas coordenadas.

Cada nó na matriz esparsa mantém:
- Um valor
- Coordenadas (linha e coluna)
- Ponteiros para os nós adjacentes (superior, inferior, esquerdo, direito)

### 3.2 Estrutura de um Nó

```c
// Em C
typedef struct NoM {
    int valor;
    int linha, coluna;
    struct NoM* sup;
    struct NoM* inf;
    struct NoM* esq;
    struct NoM* dir;
} NoM;
```

```java
// Em Java
class NoM {
    int valor;
    int linha, coluna;
    NoM sup;
    NoM inf;
    NoM esq;
    NoM dir;
    
    public NoM(int valor, int linha, int coluna) {
        this.valor = valor;
        this.linha = linha;
        this.coluna = coluna;
        this.sup = null;
        this.inf = null;
        this.esq = null;
        this.dir = null;
    }
}
```

### 3.3 Representação Visual

```
         C0     C1     C2     C3
      +------+------+------+------+
      |      |      |      |      |
      v      v      v      v      v
R0 → [H] → [C0] → [C1] → [C2] → [C3]
      |
      v
R1 → [R1] → [1,0] → [1,2]
      |        |       |
      v        v       v
R2 → [R2] → [2,0] → [2,2]
      |
      v
R3 → [R3]
```

Onde:
- [H] é o nó cabeça da matriz
- [Ri] são os nós cabeça das linhas
- [Cj] são os nós cabeça das colunas
- [i,j] são os nós com valores não-nulos nas coordenadas (i,j)

### 3.4 Implementação da Matriz Esparsa

```c
// Em C
typedef struct MatrizEsparsa {
    NoM* cabeca;
    int linhas, colunas;
} MatrizEsparsa;

MatrizEsparsa* criarMatriz(int linhas, int colunas) {
    MatrizEsparsa* matriz = (MatrizEsparsa*) malloc(sizeof(MatrizEsparsa));
    if (matriz == NULL) return NULL;
    
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    
    // Criar nó cabeça
    matriz->cabeca = (NoM*) malloc(sizeof(NoM));
    if (matriz->cabeca == NULL) {
        free(matriz);
        return NULL;
    }
    
    matriz->cabeca->linha = -1;
    matriz->cabeca->coluna = -1;
    matriz->cabeca->valor = 0;
    matriz->cabeca->sup = matriz->cabeca;
    matriz->cabeca->inf = matriz->cabeca;
    matriz->cabeca->esq = matriz->cabeca;
    matriz->cabeca->dir = matriz->cabeca;
    
    // Criar nós cabeça para linhas
    NoM* ultimaLinha = matriz->cabeca;
    for (int i = 0; i < linhas; i++) {
        NoM* noLinha = (NoM*) malloc(sizeof(NoM));
        if (noLinha == NULL) continue;
        
        noLinha->linha = i;
        noLinha->coluna = -1;
        noLinha->valor = 0;
        noLinha->sup = NULL;
        noLinha->inf = NULL;
        noLinha->dir = noLinha;  // Aponta para si mesmo (lista vazia)
        noLinha->esq = noLinha;  // Aponta para si mesmo (lista vazia)
        
        // Inserção na lista de linhas
        ultimaLinha->inf = noLinha;
        noLinha->sup = ultimaLinha;
        noLinha->inf = matriz->cabeca;
        matriz->cabeca->sup = noLinha;
        
        ultimaLinha = noLinha;
    }
    
    // Criar nós cabeça para colunas
    NoM* ultimaColuna = matriz->cabeca;
    for (int j = 0; j < colunas; j++) {
        NoM* noColuna = (NoM*) malloc(sizeof(NoM));
        if (noColuna == NULL) continue;
        
        noColuna->linha = -1;
        noColuna->coluna = j;
        noColuna->valor = 0;
        noColuna->dir = NULL;
        noColuna->esq = NULL;
        noColuna->sup = noColuna;  // Aponta para si mesmo (lista vazia)
        noColuna->inf = noColuna;  // Aponta para si mesmo (lista vazia)
        
        // Inserção na lista de colunas
        ultimaColuna->dir = noColuna;
        noColuna->esq = ultimaColuna;
        noColuna->dir = matriz->cabeca;
        matriz->cabeca->esq = noColuna;
        
        ultimaColuna = noColuna;
    }
    
    return matriz;
}
```

```java
// Em Java
class MatrizEsparsa {
    NoM cabeca;
    int linhas, colunas;
    
    public MatrizEsparsa(int linhas, int colunas) {
        this.linhas = linhas;
        this.colunas = colunas;
        
        // Criar nó cabeça
        this.cabeca = new NoM(0, -1, -1);
        this.cabeca.sup = this.cabeca;
        this.cabeca.inf = this.cabeca;
        this.cabeca.esq = this.cabeca;
        this.cabeca.dir = this.cabeca;
        
        // Criar nós cabeça para linhas
        NoM ultimaLinha = this.cabeca;
        for (int i = 0; i < linhas; i++) {
            NoM noLinha = new NoM(0, i, -1);
            noLinha.dir = noLinha;  // Aponta para si mesmo (lista vazia)
            noLinha.esq = noLinha;  // Aponta para si mesmo (lista vazia)
            
            // Inserção na lista de linhas
            ultimaLinha.inf = noLinha;
            noLinha.sup = ultimaLinha;
            noLinha.inf = this.cabeca;
            this.cabeca.sup = noLinha;
            
            ultimaLinha = noLinha;
        }
        
        // Criar nós cabeça para colunas
        NoM ultimaColuna = this.cabeca;
        for (int j = 0; j < colunas; j++) {
            NoM noColuna = new NoM(0, -1, j);
            noColuna.sup = noColuna;  // Aponta para si mesmo (lista vazia)
            noColuna.inf = noColuna;  // Aponta para si mesmo (lista vazia)
            
            // Inserção na lista de colunas
            ultimaColuna.dir = noColuna;
            noColuna.esq = ultimaColuna;
            noColuna.dir = this.cabeca;
            this.cabeca.esq = noColuna;
            
            ultimaColuna = noColuna;
        }
    }
}
```

### 3.5 Operações Básicas

#### 3.5.1 Inserção de Elemento

```c
// Em C
void inserir(MatrizEsparsa* matriz, int linha, int coluna, int valor) {
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        return;  // Fora dos limites
    }
    
    // Se valor for zero, remover elemento se existir
    if (valor == 0) {
        remover(matriz, linha, coluna);
        return;
    }
    
    // Buscar nó cabeça da linha
    NoM* linhaAtual = matriz->cabeca->inf;
    while (linhaAtual != matriz->cabeca && linhaAtual->linha < linha) {
        linhaAtual = linhaAtual->inf;
    }
    if (linhaAtual == matriz->cabeca || linhaAtual->linha > linha) {
        return;  // Linha não encontrada
    }
    
    // Buscar nó cabeça da coluna
    NoM* colunaAtual = matriz->cabeca->dir;
    while (colunaAtual != matriz->cabeca && colunaAtual->coluna < coluna) {
        colunaAtual = colunaAtual->dir;
    }
    if (colunaAtual == matriz->cabeca || colunaAtual->coluna > coluna) {
        return;  // Coluna não encontrada
    }
    
    // Verificar se já existe um elemento na posição
    NoM* atual = linhaAtual->dir;
    while (atual != linhaAtual && atual->coluna < coluna) {
        atual = atual->dir;
    }
    
    if (atual != linhaAtual && atual->coluna == coluna) {
        // Elemento já existe, atualizar valor
        atual->valor = valor;
        return;
    }
    
    // Criar novo nó
    NoM* novo = (NoM*) malloc(sizeof(NoM));
    if (novo == NULL) return;
    
    novo->linha = linha;
    novo->coluna = coluna;
    novo->valor = valor;
    
    // Inserir na lista horizontal (linha)
    novo->esq = atual->esq;
    novo->dir = atual;
    atual->esq->dir = novo;
    atual->esq = novo;
    
    // Inserir na lista vertical (coluna)
    atual = colunaAtual->inf;
    while (atual != colunaAtual && atual->linha < linha) {
        atual = atual->inf;
    }
    
    novo->sup = atual->sup;
    novo->inf = atual;
    atual->sup->inf = novo;
    atual->sup = novo;
}
```

```java
// Em Java
void inserir(int linha, int coluna, int valor) {
    if (linha < 0 || linha >= this.linhas || coluna < 0 || coluna >= this.colunas) {
        return;  // Fora dos limites
    }
    
    // Se valor for zero, remover elemento se existir
    if (valor == 0) {
        remover(linha, coluna);
        return;
    }
    
    // Buscar nó cabeça da linha
    NoM linhaAtual = this.cabeca.inf;
    while (linhaAtual != this.cabeca && linhaAtual.linha < linha) {
        linhaAtual = linhaAtual.inf;
    }
    if (linhaAtual == this.cabeca || linhaAtual.linha > linha) {
        return;  // Linha não encontrada
    }
    
    // Buscar nó cabeça da coluna
    NoM colunaAtual = this.cabeca.dir;
    while (colunaAtual != this.cabeca && colunaAtual.coluna < coluna) {
        colunaAtual = colunaAtual.dir;
    }
    if (colunaAtual == this.cabeca || colunaAtual.coluna > coluna) {
        return;  // Coluna não encontrada
    }
    
    // Verificar se já existe um elemento na posição
    NoM atual = linhaAtual.dir;
    while (atual != linhaAtual && atual.coluna < coluna) {
        atual = atual.dir;
    }
    
    if (atual != linhaAtual && atual.coluna == coluna) {
        // Elemento já existe, atualizar valor
        atual.valor = valor;
        return;
    }
    
    // Criar novo nó
    NoM novo = new NoM(valor, linha, coluna);
    
    // Inserir na lista horizontal (linha)
    novo.esq = atual.esq;
    novo.dir = atual;
    atual.esq.dir = novo;
    atual.esq = novo;
    
    // Inserir na lista vertical (coluna)
    atual = colunaAtual.inf;
    while (atual != colunaAtual && atual.linha < linha) {
        atual = atual.inf;
    }
    
    novo.sup = atual.sup;
    novo.inf = atual;
    atual.sup.inf = novo;
    atual.sup = novo;
}
```

#### 3.5.2 Busca de Elemento

```c
// Em C
int obterValor(MatrizEsparsa* matriz, int linha, int coluna) {
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        return 0;  // Fora dos limites
    }
    
    // Buscar nó cabeça da linha
    NoM* linhaAtual = matriz->cabeca->inf;
    while (linhaAtual != matriz->cabeca && linhaAtual->linha < linha) {
        linhaAtual = linhaAtual->inf;
    }
    if (linhaAtual == matriz->cabeca || linhaAtual->linha > linha) {
        return 0;  // Linha não encontrada
    }
    
    // Buscar elemento na linha
    NoM* atual = linhaAtual->dir;
    while (atual != linhaAtual && atual->coluna < coluna) {
        atual = atual->dir;
    }
    
    if (atual != linhaAtual && atual->coluna == coluna) {
        return atual->valor;  // Elemento encontrado
    }
    
    return 0;  // Elemento não encontrado (valor padrão = 0)
}
```

```java
// Em Java
int obterValor(int linha, int coluna) {
    if (linha < 0 || linha >= this.linhas || coluna < 0 || coluna >= this.colunas) {
        return 0;  // Fora dos limites
    }
    
    // Buscar nó cabeça da linha
    NoM linhaAtual = this.cabeca.inf;
    while (linhaAtual != this.cabeca && linhaAtual.linha < linha) {
        linhaAtual = linhaAtual.inf;
    }
    if (linhaAtual == this.cabeca || linhaAtual.linha > linha) {
        return 0;  // Linha não encontrada
    }
    
    // Buscar elemento na linha
    NoM atual = linhaAtual.dir;
    while (atual != linhaAtual && atual.coluna < coluna) {
        atual = atual.dir;
    }
    
    if (atual != linhaAtual && atual.coluna == coluna) {
        return atual.valor;  // Elemento encontrado
    }
    
    return 0;  // Elemento não encontrado (valor padrão = 0)
}
```

#### 3.5.3 Remoção de Elemento

```c
// Em C
void remover(MatrizEsparsa* matriz, int linha, int coluna) {
    if (linha < 0 || linha >= matriz->linhas || coluna < 0 || coluna >= matriz->colunas) {
        return;  // Fora dos limites
    }
    
    // Buscar nó cabeça da linha
    NoM* linhaAtual = matriz->cabeca->inf;
    while (linhaAtual != matriz->cabeca && linhaAtual->linha < linha) {
        linhaAtual = linhaAtual->inf;
    }
    if (linhaAtual == matriz->cabeca || linhaAtual->linha > linha) {
        return;  // Linha não encontrada
    }
    
    // Buscar elemento na linha
    NoM* atual = linhaAtual->dir;
    while (atual != linhaAtual && atual->coluna < coluna) {
        atual = atual->dir;
    }
    
    if (atual != linhaAtual && atual->coluna == coluna) {
        // Remover da lista horizontal
        atual->esq->dir = atual->dir;
        atual->dir->esq = atual->esq;
        
        // Remover da lista vertical
        atual->sup->inf = atual->inf;
        atual->inf->sup = atual->sup;
        
        free(atual);
    }
}
```

```java
// Em Java
void remover(int linha, int coluna) {
    if (linha < 0 || linha >= this.linhas || coluna < 0 || coluna >= this.colunas) {
        return;  // Fora dos limites
    }
    
    // Buscar nó cabeça da linha
    NoM linhaAtual = this.cabeca.inf;
    while (linhaAtual != this.cabeca && linhaAtual.linha < linha) {
        linhaAtual = linhaAtual.inf;
    }
    if (linhaAtual == this.cabeca || linhaAtual.linha > linha) {
        return;  // Linha não encontrada
    }
    
    // Buscar elemento na linha
    NoM atual = linhaAtual.dir;
    while (atual != linhaAtual && atual.coluna < coluna) {
        atual = atual.dir;
    }
    
    if (atual != linhaAtual && atual.coluna == coluna) {
        // Remover da lista horizontal
        atual.esq.dir = atual.dir;
        atual.dir.esq = atual.esq;
        
        // Remover da lista vertical
        atual.sup.inf = atual.inf;
        atual.inf.sup = atual.sup;
    }
}
```

### 3.6 Complexidade

| Operação | Complexidade | Observação |
|----------|--------------|------------|
| Inserção | O(r + c) | r = número de elementos na linha, c = número de elementos na coluna |
| Busca | O(min(r, c)) | Podemos buscar pela linha ou coluna, o que for mais eficiente |
| Remoção | O(min(r, c)) | Após encontrar o elemento, a remoção é O(1) |
| Soma/Multiplicação | O(n*m) | n, m são número de elementos não-nulos nas matrizes |

### 3.7 Vantagens e Desvantagens

**Vantagens:**
- Economia de memória para matrizes esparsas (muitos zeros)
- Operações eficientes quando há poucos elementos não-nulos
- Permite navegação por linha ou coluna

**Desvantagens:**
- Implementação complexa
- Acesso a elementos pode ser mais lento que em matrizes convencionais
- Overhead de memória para ponteiros em cada nó

## 4. Comparação Entre Estruturas

| Característica | Lista Simples | Lista Dupla | Matriz Esparsa |
|----------------|---------------|-------------|----------------|
| **Overhead de memória** | Baixo (1 ponteiro) | Médio (2 ponteiros) | Alto (4+ ponteiros) |
| **Navegação** | Unidirecional | Bidirecional | Multidirecional |
| **Complexidade de implementação** | Simples | Moderada | Alta |
| **Uso típico** | Pilhas, filas, listas | Listas, deques, editores | Matrizes grandes com muitos zeros |
| **Elemento predecessor** | Não acessível | Acessível em O(1) | Acessível em O(1) |
| **Remoção com nó conhecido** | O(n) | O(1) | O(1) |
| **Eficiência de espaço** | Boa | Média | Excelente para matrizes esparsas |

## 5. Desafios Resolvidos

### 5.1 Problema para Lista Simplesmente Encadeada

**Problema:** Implementar um algoritmo para encontrar o k-ésimo elemento a partir do final de uma lista encadeada em uma única passagem.

**Solução:**

```c
// Em C
No* encontrarKesimoDoFinal(No* head, int k) {
    if (head == NULL || k <= 0) return NULL;
    
    No* rapido = head;
    No* lento = head;
    
    // Avançar o ponteiro rápido k posições
    for (int i = 0; i < k; i++) {
        if (rapido == NULL) return NULL;  // Lista menor que k
        rapido = rapido->prox;
    }
    
    // Mover ambos os ponteiros até que o rápido chegue ao final
    while (rapido != NULL) {
        rapido = rapido->prox;
        lento = lento->prox;
    }
    
    return lento;  // Este é o k-ésimo elemento a partir do final
}
```

```java
// Em Java
No encontrarKesimoDoFinal(int k) {
    if (head == null || k <= 0) return null;
    
    No rapido = head;
    No lento = head;
    
    // Avançar o ponteiro rápido k posições
    for (int i = 0; i < k; i++) {
        if (rapido == null) return null;  // Lista menor que k
        rapido = rapido.prox;
    }
    
    // Mover ambos os ponteiros até que o rápido chegue ao final
    while (rapido != null) {
        rapido = rapido.prox;
        lento = lento.prox;
    }
    
    return lento;  // Este é o k-ésimo elemento a partir do final
}
```

**Explicação:**
1. Utilizamos dois ponteiros: "rápido" e "lento"
2. Avançamos o ponteiro "rápido" k posições à frente
3. Depois, movemos ambos os ponteiros simultaneamente
4. Quando o "rápido" chegar ao final, o "lento" estará exatamente k posições atrás
5. Complexidade: O(n) em tempo, O(1) em espaço adicional

### 5.2 Problema para Lista Duplamente Encadeada

**Problema:** Implementar um LRU Cache (Least Recently Used) com operações get e put em tempo O(1).

**Solução:**

```java
// Em Java
class LRUCache {
    private class Node {
        int key;
        int value;
        Node prev;
        Node next;
        
        Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }
    
    private int capacity;
    private Map<Integer, Node> cache; // HashMap para acesso O(1)
    private Node head; // Nó mais recentemente usado
    private Node tail; // Nó menos recentemente usado
    
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.cache = new HashMap<>();
        
        // Inicializar lista duplamente encadeada
        this.head = new Node(0, 0);
        this.tail = new Node(0, 0);
        head.next = tail;
        tail.prev = head;
    }
    
    // Adicionar nó após o head (mais recentemente usado)
    private void addNode(Node node) {
        node.prev = head;
        node.next = head.next;
        
        head.next.prev = node;
        head.next = node;
    }
    
    // Remover nó da lista
    private void removeNode(Node node) {
        Node prev = node.prev;
        Node next = node.next;
        
        prev.next = next;
        next.prev = prev;
    }
    
    // Mover para o início (marcar como recentemente usado)
    private void moveToHead(Node node) {
        removeNode(node);
        addNode(node);
    }
    
    // Remover o nó menos recentemente usado
    private Node popTail() {
        Node res = tail.prev;
        removeNode(res);
        return res;
    }
    
    public int get(int key) {
        Node node = cache.get(key);
        if (node == null) {
            return -1; // Não encontrado
        }
        
        // Mover para o início (marca como recentemente usado)
        moveToHead(node);
        return node.value;
    }
    
    public void put(int key, int value) {
        Node node = cache.get(key);
        
        if (node == null) {
            // Criar novo nó
            Node newNode = new Node(key, value);
            
            // Adicionar ao cache
            cache.put(key, newNode);
            
            // Adicionar à lista
            addNode(newNode);
            
            // Verificar capacidade
            if (cache.size() > capacity) {
                // Remover o menos recentemente usado
                Node tail = popTail();
                cache.remove(tail.key);
            }
        } else {
            // Atualizar valor e mover para o início
            node.value = value;
            moveToHead(node);
        }
    }
}
```

**Explicação:**
1. Utilizamos uma lista duplamente encadeada para manter a ordem de uso (mais recente -> menos recente)
2. Um HashMap mapeia chaves para nós, permitindo acesso em O(1)
3. Quando um elemento é acessado ou adicionado, ele vai para o início da lista (mais recentemente usado)
4. Quando o cache atinge capacidade máxima, removemos o elemento no final da lista (menos recentemente usado)
5. A lista duplamente encadeada permite inserção e remoção em O(1), essencial para a eficiência do LRU Cache

### 5.3 Problema para Matriz Esparsa

**Problema:** Adicionar duas matrizes esparsas e retornar o resultado como uma nova matriz esparsa.

**Solução:**

```java
// Em Java
MatrizEsparsa somarMatrizes(MatrizEsparsa A, MatrizEsparsa B) {
    // Verificar dimensões compatíveis
    if (A.linhas != B.linhas || A.colunas != B.colunas) {
        throw new IllegalArgumentException("Dimensões incompatíveis");
    }
    
    // Criar matriz resultado
    MatrizEsparsa resultado = new MatrizEsparsa(A.linhas, A.colunas);
    
    // Percorrer todas as linhas da matriz A
    NoM linhaA = A.cabeca.inf;
    while (linhaA != A.cabeca) {
        int i = linhaA.linha;
        
        // Percorrer elementos não-nulos na linha i
        NoM elementoA = linhaA.dir;
        while (elementoA != linhaA) {
            int j = elementoA.coluna;
            int valorA = elementoA.valor;
            
            // Obter valor correspondente da matriz B
            int valorB = B.obterValor(i, j);
            
            // Inserir soma na matriz resultado
            int soma = valorA + valorB;
            if (soma != 0) {
                resultado.inserir(i, j, soma);
            }
            
            elementoA = elementoA.dir;
        }
        
        linhaA = linhaA.inf;
    }
    
    // Agora percorrer B para encontrar elementos não zero que não existem em A
    NoM linhaB = B.cabeca.inf;
    while (linhaB != B.cabeca) {
        int i = linhaB.linha;
        
        NoM elementoB = linhaB.dir;
        while (elementoB != linhaB) {
            int j = elementoB.coluna;
            
            // Verificar se este elemento já foi adicionado ao resultado
            // (Se existe em A, já foi processado na parte anterior)
            if (A.obterValor(i, j) == 0) {
                resultado.inserir(i, j, elementoB.valor);
            }
            
            elementoB = elementoB.dir;
        }
        
        linhaB = linhaB.inf;
    }
    
    return resultado;
}
```

**Explicação:**
1. Criamos uma nova matriz esparsa para armazenar o resultado
2. Percorremos todos os elementos não-nulos da matriz A
3. Para cada elemento em A, buscamos o elemento correspondente em B
4. Somamos os valores e inserimos o resultado (se não for zero)
5. Depois, percorremos os elementos de B que não existem em A
6. A complexidade será O(nnz_A + nnz_B), onde nnz é o número de elementos não-nulos em cada matriz
7. Esta abordagem é eficiente para matrizes esparsas, pois só processamos elementos não-nulos

---

Este README fornece uma visão detalhada das estruturas de dados flexíveis, suas implementações e operações. As implementações estão em C e Java para facilitar o entendimento em ambas as linguagens. Os problemas resolvidos demonstram aplicações práticas de cada estrutura e técnicas comuns para lidar com elas.

Para obter sucesso no trabalho com estruturas flexíveis:
1. Mantenha o controle cuidadoso dos ponteiros para evitar vazamentos de memória
2. Utilize testes de borda (casos limite) ao implementar operações
3. Considere o trade-off entre tempo de execução e consumo de memória ao escolher uma estrutura
4. Lembre-se de liberar a memória alocada quando a estrutura não for mais necessária (em C)