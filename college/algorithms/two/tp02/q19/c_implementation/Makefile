# Makefile para compilar os algoritmos de ordenação em C

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c99

# Diretório de resultados
RESULTS_DIR = ../results

# Arquivos de origem
SRCS = sorting_algorithms.c performance_test.c main.c
OBJS = $(SRCS:.c=.o)
EXEC = sort_analyzer

# Regra padrão
all: $(EXEC)

# Compilar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -lm

# Regra para objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Criar o diretório de resultados se não existir
$(RESULTS_DIR):
	mkdir -p $(RESULTS_DIR)

# Executar o programa
run: $(EXEC) $(RESULTS_DIR)
	./$(EXEC) $(RESULTS_DIR)

# Limpar arquivos temporários
clean:
	rm -f $(OBJS) $(EXEC)

# Limpar tudo, incluindo resultados
clean-all: clean
	rm -rf $(RESULTS_DIR)

# Dependências
sorting_algorithms.o: sorting_algorithms.c sorting_algorithms.h
performance_test.o: performance_test.c sorting_algorithms.h
main.o: main.c sorting_algorithms.h

.PHONY: all run clean clean-all