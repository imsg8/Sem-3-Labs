#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

void push(struct Stack *stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
        return;
    }
    stack->data[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    int decimalNumber, remainder;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber < 0) {
        printf("Negative numbers are not supported.\n");
        return 1;
    }

    if (decimalNumber == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }

    while (decimalNumber > 0) {
        remainder = decimalNumber % 2;
        push(&stack, remainder);
        decimalNumber = decimalNumber / 2;
    }

    printf("Binary representation: ");

    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }

    printf("\n");

    return 0;
}
