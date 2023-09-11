#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Get the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

// Convert infix to prefix
void infixToPrefix(char infix[], char prefix[]) {
    Stack operatorStack;
    initialize(&operatorStack);
    int length = strlen(infix);

    for (int i = 0; i < length; i++) {
        char token = infix[i];

        if (token == ' ' || token == '\t') {
            // Skip whitespace
            continue;
        } else if (isdigit(token) || isalpha(token)) {
            // Operand (number or variable)
            while (i < length && (isdigit(infix[i]) || isalpha(infix[i]))) {
                prefix[strlen(prefix)] = infix[i++];
            }
            prefix[strlen(prefix)] = ' '; // Separate operands with space
            i--;
        } else if (token == '(') {
            // Opening parenthesis
            push(&operatorStack, token);
        } else if (token == ')') {
            // Closing parenthesis
            while (!isEmpty(&operatorStack) && operatorStack.data[operatorStack.top] != '(') {
                prefix[strlen(prefix)] = pop(&operatorStack);
                prefix[strlen(prefix)] = ' ';
            }
            // Pop and discard the matching opening parenthesis
            if (!isEmpty(&operatorStack) && operatorStack.data[operatorStack.top] == '(') {
                pop(&operatorStack);
            }
        } else {
            // Operator
            while (!isEmpty(&operatorStack) && precedence(operatorStack.data[operatorStack.top]) >= precedence(token)) {
                prefix[strlen(prefix)] = pop(&operatorStack);
                prefix[strlen(prefix)] = ' ';
            }
            push(&operatorStack, token);
        }
    }

    // Pop any remaining operators from the operator stack
    while (!isEmpty(&operatorStack)) {
        prefix[strlen(prefix)] = pop(&operatorStack);
        prefix[strlen(prefix)] = ' ';
    }

    // Reverse the prefix expression to get the final result
    strrev(prefix);
}

int main() {
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    gets(infix); // This is not safe, use fgets in a real program

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
