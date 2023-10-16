#include <stdio.h>
#include <stdlib.h>

struct Node {
    int height;
    struct Node* next;
};

void insert(struct Node** head, int height) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->height = height;
    newNode->next = NULL;

    struct Node* current = *head;
    if (current == NULL || height < current->height) {
        newNode->next = current;
        *head = newNode;
        return;
    }

    while (current->next != NULL && height > current->next->height) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d->", head->height);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;

    while (list1 != NULL) {
        insert(&result, list1->height);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        insert(&result, list2->height);
        list2 = list2->next;
    }

    return result;
}

int main() {
    int N1, N2;
    scanf("%d %d", &N1, &N2);

    struct Node* classA = NULL;
    struct Node* classB = NULL;

    for (int i = 0; i < N1; i++) {
        int height;
        scanf("%d", &height);
        insert(&classA, height);
    }

    for (int i = 0; i < N2; i++) {
        int height;
        scanf("%d", &height);
        insert(&classB, height);
    }

    printf("Line of Class A: ");
    display(classA);

    printf("Line of Class B: ");
    display(classB);

    struct Node* jointClass = mergeLists(classA, classB);
    printf("Joint Class Line: ");
    display(jointClass);

    return 0;
}
