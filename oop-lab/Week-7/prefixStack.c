#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

// Define a stack structure
typedef struct {
    int top;
    int data[MAX_STACK_SIZE];
} Stack;

// Initialize an empty stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

// Evaluate a prefix expression
int evaluatePrefix(char expression[]) {
    Stack stack;
    initialize(&stack);

    int length = strlen(expression);

    // Reverse the expression
    for (int i = 0; i < length / 2; i++) {
        char temp = expression[i];
        expression[i] = expression[length - i - 1];
        expression[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&stack, operand1 / operand2);
                    } else {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    break;
            }
        }
    }

    // The final result should be on the stack
    return pop(&stack);
}

int main() {
    char expression[100];
    printf("Enter a prefix expression: ");
    gets(expression); // This is not safe, use fgets in a real program

    int result = evaluatePrefix(expression);
    printf("Result: %d\n", result);

    return 0;
}
