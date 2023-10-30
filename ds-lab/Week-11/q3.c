#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a node in the expression tree
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Structure for a stack node
typedef struct StackNode {
    TreeNode* data;
    struct StackNode* next;
} StackNode;

// Function to create a new tree node
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(StackNode** top, TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = node;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from the stack
TreeNode* pop(StackNode** top) {
    if (*top == NULL) {
        return NULL;
    }
    StackNode* temp = *top;
    *top = (*top)->next;
    TreeNode* node = temp->data;
    free(temp);
    return node;
}

// Function to build an expression tree from a postfix expression
TreeNode* buildExpressionTree(char postfix[]) {
    StackNode* stack = NULL;
    for (int i = 0; postfix[i]; i++) {
        char symbol = postfix[i];
        TreeNode* node = createNode(symbol);

        if (isdigit(symbol)) {
            push(&stack, node);
        } else {
            // Operator encountered, pop two operands from the stack
            TreeNode* operand2 = pop(&stack);
            TreeNode* operand1 = pop(&stack);

            // Set the operands as the left and right children of the operator
            node->right = operand2;
            node->left = operand1;

            // Push the operator back to the stack
            push(&stack, node);
        }
    }
    // The final element in the stack is the root of the expression tree
    return pop(&stack);
}

// Function to evaluate an expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (isdigit(root->data)) {
        return root->data - '0';
    }
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            return leftValue / rightValue;
    }
    return 0;
}

int main() {
    char postfixExpression[] = "23*5+";
    TreeNode* root = buildExpressionTree(postfixExpression);
    printf("Postfix Expression: %s\n", postfixExpression);
    printf("Result of Evaluation: %d\n", evaluateExpressionTree(root));

    return 0;
}
