#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top1; // Top of the first stack
    int top2; // Top of the second stack
} TwoStacks;

// Initialize the two stacks
void initialize(TwoStacks *stacks) {
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE;
}

// Check if the first stack is empty
int isEmpty1(TwoStacks *stacks) {
    return stacks->top1 == -1;
}

// Check if the second stack is empty
int isEmpty2(TwoStacks *stacks) {
    return stacks->top2 == MAX_SIZE;
}

// Push an element onto the first stack
void push1(TwoStacks *stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->data[++stacks->top1] = value;
    } else {
        printf("Stack 1 overflow\n");
        exit(1);
    }
}

// Push an element onto the second stack
void push2(TwoStacks *stacks, int value) {
    if (stacks->top1 < stacks->top2 - 1) {
        stacks->data[--stacks->top2] = value;
    } else {
        printf("Stack 2 overflow\n");
        exit(1);
    }
}

// Pop an element from the first stack
int pop1(TwoStacks *stacks) {
    if (!isEmpty1(stacks)) {
        return stacks->data[stacks->top1--];
    } else {
        printf("Stack 1 underflow\n");
        exit(1);
    }
}

// Pop an element from the second stack
int pop2(TwoStacks *stacks) {
    if (!isEmpty2(stacks)) {
        return stacks->data[stacks->top2++];
    } else {
        printf("Stack 2 underflow\n");
        exit(1);
    }
}

int main() {
    TwoStacks stacks;
    initialize(&stacks);

    int choice, value;

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(&stacks, value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(&stacks, value);
                break;
            case 3:
                if (!isEmpty1(&stacks)) {
                    printf("Popped from Stack 1: %d\n", pop1(&stacks));
                } else {
                    printf("Stack 1 is empty.\n");
                }
                break;
            case 4:
                if (!isEmpty2(&stacks)) {
                    printf("Popped from Stack 2: %d\n", pop2(&stacks));
                } else {
                    printf("Stack 2 is empty.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
