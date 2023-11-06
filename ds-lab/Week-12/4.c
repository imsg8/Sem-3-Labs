#include <stdio.h>
#include <stdlib.h>

struct tn {
    int data;
    struct tn* l;
    struct tn* r;
};

struct tn* constructBinaryTree(int* pre, int* post, int* preIndex, int postStart, int postEnd, int size) {
    if (*preIndex >= size || postStart > postEnd) {
        return NULL;
    }

    struct tn* root = (struct tn*)malloc(sizeof(struct tn));
    root->data = pre[(*preIndex)++];
    root->l = root->r = NULL;

    if (postStart == postEnd) {
        return root;
    }

    int postIndex;
    for (postIndex = postStart; postIndex <= postEnd; postIndex++) {
        if (post[postIndex] == pre[*preIndex]) {
            break;
        }
    }

    if (postIndex <= postEnd) {
        root->l = constructBinaryTree(pre, post, preIndex, postStart, postIndex, size);
        root->r = constructBinaryTree(pre, post, preIndex, postIndex + 1, postEnd, size);
    }

    return root;
}

void inOrderTraversal(struct tn* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->l);
    printf("%d ", root->data);
    inOrderTraversal(root->r);
}

int main() {
    int preOrder[] = {1, 2, 4, 5, 3, 6, 7};
    int postOrder[] = {4, 5, 2, 6, 7, 3, 1};
    int preIndex = 0;
    int size = sizeof(preOrder) / sizeof(preOrder[0]);

    struct tn* root = constructBinaryTree(preOrder, postOrder, &preIndex, 0, size - 1, size);

    printf("In-order traversal of the constructed binary tree: ");
    inOrderTraversal(root);
    printf("\n");
    return 0;
}
