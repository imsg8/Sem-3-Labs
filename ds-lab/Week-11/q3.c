#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a tree node structure
struct tn {
    char data;
    struct tn* l;
    struct tn* r;
};

// Function to create a new tree node
struct tn* newNode(char data) {
    struct tn* node = (struct tn*)malloc(sizeof(struct tn));
    node->data = data;
    node->l = NULL;
    node->r = NULL;
    return node;
}

// Function to build an expression tree from a pof expression
struct tn* bet(const char* pof) {
    struct tn* root = NULL;
    struct tn* stack[100]; // Assume pof expression is not too long
    int top = -1;
    
    for (int i = 0; pof[i]; i++) {
        if (isdigit(pof[i])) {
            root = newNode(pof[i]);
            stack[++top] = root;
        } else {
            if (top < 1) {
                printf("Invalid pof expression\n");
                return NULL;
            }
            root = newNode(pof[i]);
            root->r = stack[top--];
            root->l = stack[top--];
            stack[++top] = root;
        }
    }
    
    if (top == 0) {
        return stack[0];
    } else {
        printf("Invalid pof expression\n");
        return NULL;
    }
}

// Function to evaluate an expression tree
int eval(struct tn* root) {
    if (root) {
        if (isdigit(root->data)) {
            return root->data - '0'; // Convert char to int
        }
        int l = eval(root->l);
        int r = eval(root->r);
        switch (root->data) {
            case '+': return l + r;
            case '-': return l - r;
            case '*': return l * r;
            case '/': return l / r;
        }
    }
    return 0;
}

int main() {
    const char* pof = "23*5+4-5/"; // Example pof expression
    struct tn* root = bet(pof);
    if (root) {
        printf("Postfix Expression: %s\n", pof);
        printf("Result: %d\n", eval(root));
    }
    
    return 0;
}
