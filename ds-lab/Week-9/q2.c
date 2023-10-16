#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert an element at the end of a linked list
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to display a linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to find the UNION of two linked lists
struct Node* unionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        result = insert(result, list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        result = insert(result, list2->data);
        list2 = list2->next;
    }
    return result;
}

// Function to find the INTERSECTION of two linked lists
struct Node* intersectionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        struct Node* temp = list2;
        while (temp != NULL) {
            if (list1->data == temp->data) {
                result = insert(result, list1->data);
                break;
            }
            temp = temp->next;
        }
        list1 = list1->next;
    }
    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    list1 = insert(list1, 1);
    list1 = insert(list1, 2);
    list1 = insert(list1, 3);

    list2 = insert(list2, 2);
    list2 = insert(list2, 3);
    list2 = insert(list2, 4);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node* unionResult = unionLists(list1, list2);
    printf("UNION: ");
    display(unionResult);

    struct Node* intersectionResult = intersectionLists(list1, list2);
    printf("INTERSECTION: ");
    display(intersectionResult);

    return 0;
}
