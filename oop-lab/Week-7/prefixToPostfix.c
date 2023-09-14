#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a stack structure
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Initialize an empty stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push a character onto the stack
void push(Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

// Pop a character from the stack
char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Convert prefix to postfix
void prefixToPostfix(char prefix[], char postfix[]) {
    Stack stack;
    initialize(&stack);
    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        char token = prefix[i];

        if (isdigit(token) || isalpha(token)) {
            // Operand (number or variable)
            postfix[strlen(postfix)] = token;
        } else if (isOperator(token)) {
            // Operator
            char operand1 = pop(&stack);
            char operand2 = pop(&stack);
            char result[3] = {operand1, operand2, token};
            strcat(postfix, result);
            push(&stack, result[0]);
        }
    }
}

int main() {
    char prefix[100], postfix[100];
    printf("Enter a prefix expression: ");
    gets(prefix); // This is not safe, use fgets in a real program

    prefixToPostfix(prefix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
