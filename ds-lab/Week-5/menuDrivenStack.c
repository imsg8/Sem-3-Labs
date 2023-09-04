#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
        return;
    }

    stack->data[++stack->top] = item;
    printf("Pushed '%c' onto the stack.\n", item);
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return '\0';
    }

    char item = stack->data[stack->top--];
    return item;
}

void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%c ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);
    int choice;
    char item;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to push onto the stack: ");
                scanf(" %c", &item);
                push(&stack, item);
                break;
            case 2:
                item = pop(&stack);
                if (item != '\0') {
                    printf("Popped '%c' from the stack.\n", item);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
