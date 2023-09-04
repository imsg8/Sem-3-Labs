#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void push(struct Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int isPalindrome(char *str) {
    struct Stack stack;
    initialize(&stack);

    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++) {
        char ch = str[i];
        if (isalnum(ch)) 
        {
            push(&stack, ch);
        }
    }

    for (i = 0; i < len; i++) {
        char ch = str[i];
        if (isalnum(ch)) {
            char stackChar = pop(&stack);
            if (stackChar != ch && stackChar != ch - 32 && stackChar != ch + 32) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
