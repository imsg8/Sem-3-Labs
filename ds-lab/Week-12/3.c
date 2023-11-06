#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool printAncestors(struct TreeNode* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key || printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return true;
    }

    return false;
}

int main() {
    struct TreeNode* root = &(struct TreeNode){10, &(struct TreeNode){5, NULL, NULL}, &(struct TreeNode){15, &(struct TreeNode){12, NULL, NULL}, &(struct TreeNode){20, NULL, NULL}}};
    int key = 12;

    printf("Ancestors of key %d are: ", key);
    if (!printAncestors(root, key)) {
        printf("Key not found in the tree.\n");
    } else {
        printf("\n");
    }

    return 0;
}
