#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the doubly linked list
struct Node {
    char data[50];
    struct Node* next;
    struct Node* prev;
};

// Function to reverse a doubly linked list
void reverseDoublyLinkedList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Function to insert a node at the end of the list
void append(struct Node** head, const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some words into the doubly linked list
    append(&head, "Hello");
    append(&head, "World");
    append(&head, "C");
    append(&head, "Programming");

    printf("Original Doubly Linked List:\n");
    printList(head);

    // Reverse the doubly linked list
    reverseDoublyLinkedList(&head);

    printf("Reversed Doubly Linked List:\n");
    printList(head);

    return 0;
}
