#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* topo;
} Stack;

void push(Stack* stack, int new_value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->next = NULL;

    if (stack->topo != NULL) {
        new_node->next = stack->topo;
    }
    stack->topo = new_node;
}

void pop(Stack* stack) {
    if (stack->topo == NULL) {
        printf("EMPTY\n");
    } else {
        stack->topo = stack->topo->next;
    }
}

void min(Stack* stack) {
    if (stack->topo == NULL) {
        printf("EMPTY\n");
    } else {
        int min_val = stack->topo->value;
        Node* current = stack->topo->next;
        while (current != NULL) {
            if (current->value < min_val) {
                min_val = current->value;
            }
            current = current->next;
        }
        printf("%d\n", min_val);
    }
}

int main() {
    int elements = 0;
    int value;
    char line[255];
    Stack* initial_stack = (Stack*)malloc(sizeof(Stack));

    scanf("%d", &elements);

    for (int i = 0; i < elements; i++) {
        scanf("%s", line);

        if (strcmp(line, "PUSH") == 0) {
            scanf("%d", &value);

            push(initial_stack, value);
        }

        if (strcmp(line, "MIN") == 0) {
            min(initial_stack);
        }

        if (strcmp(line, "POP") == 0) {
            pop(initial_stack);
        }
    }
}
