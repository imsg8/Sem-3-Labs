#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct tn {
    int val;
    struct tn* l;
    struct tn* r;
};

struct tn* cbst(int data[], int s, int e) {
    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;
    struct tn* root = (struct tn*)malloc(sizeof(struct tn));
    root->val = data[mid];
    root->l = cbst(data, s, mid - 1);
    root->r = cbst(data, mid + 1, e);
    return root;
}

bool isSameTree(struct tn* p, struct tn* q) {
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL || p->val != q->val) {
        return false;
    }

    return isSameTree(p->l, q->l) && isSameTree(p->r, q->r);
}

int main() {
    // Create two arrays for constructing BSTs
    int data1[] = {1, 2, 4};
    int data2[] = {1, 2, 3};

    // Construct BSTs from the arrays
    struct tn* root1 = cbst(data1, 0, 2);
    struct tn* root2 = cbst(data2, 0, 2);

    // Test if the two binary trees are equal using the recursive function
    bool result = isSameTree(root1, root2);

    if (result) {
        printf("The two binary trees are equal.\n");
    } else {
        printf("The two binary trees are not equal.\n");
    }

    return 0;
}
