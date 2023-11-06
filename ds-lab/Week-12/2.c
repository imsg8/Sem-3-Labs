#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct tn {
    int val;
    struct tn* l;
    struct tn* r;
};
struct tn* cbst(int data[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct tn* r = (struct tn*)malloc(sizeof(struct tn));
    r->val = data[mid];
    r->l = cbst(data, start, mid - 1);
    r->r = cbst(data, mid + 1, end);
    return r;
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
    int data1[] = {1, 2, 3};
    int data2[] = {1, 2, 3};

    // Construct BSTs from the arrays
    struct tn* r1 = cbst(data1, 0, 2);
    struct tn* r2 = cbst(data2, 0, 2);

    // Test if the two binary trees are equal using the recursive function
    bool result = isSameTree(r1, r2);

    if (result) {
        printf("The two binary trees are equal.\n");
    } else {
        printf("The two binary trees are not equal.\n");
    }

    return 0;
}
