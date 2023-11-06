#include <stdio.h>
#include <stdlib.h>

struct tn {
    int data;
    struct tn* l;
    struct tn* r;
};

struct tn* nn(int data) {
    struct tn* node = (struct tn*)malloc(sizeof(struct tn));
    node->data = data;
    node->l = NULL;
    node->r = NULL;
    return node;
}

struct tn* cpy(struct tn* og) {
    if (og == NULL) {
        return NULL;
    }
    struct tn* copy = nn(og->data);
    copy->l = cpy(og->l);
    copy->r = cpy(og->r);
    return copy;
}

void inot(struct tn* root) {
    if (root) {
        inot(root->l);
        printf("%d ", root->data);
        inot(root->r);
    }
}

int main() {
    struct tn* og = nn(1);
    og->l = nn(2);
    og->r = nn(3);
    og->l->l = nn(4);

    printf("Original Binary Tree (In-order traversal): ");
    inot(og);
    printf("\n");

    struct tn* copy = cpy(og);

    printf("Copy of Binary Tree (In-order traversal): ");
    inot(copy);
    printf("\n");

    return 0;
}
