#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node for a polynomial
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into a polynomial
void insertTerm(Node** poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        *poly = newNode;
        (*poly)->next = *poly;
    } else {
        Node* temp = *poly;
        while (temp->next != *poly) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *poly;
    }
}

// Function to display a polynomial
void displayPoly(Node* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    Node* current = poly;
    do {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != poly) {
            printf(" + ");
        }
    } while (current != poly);
    printf("\n");
}

// Function to subtract two polynomials
Node* subtractPolynomials(Node* poly1, Node* poly2) {
    if (poly1 == NULL) {
        return poly2;
    }
    if (poly2 == NULL) {
        return poly1;
    }
    Node* result = NULL;
    Node* current1 = poly1;
    do {
        insertTerm(&result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    } while (current1 != poly1);

    Node* current2 = poly2;
    do {
        insertTerm(&result, -current2->coefficient, current2->exponent);
        current2 = current2->next;
    } while (current2 != poly2);

    return result;
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    if (poly1 == NULL || poly2 == NULL) {
        return NULL;
    }
    Node* result = NULL;
    Node* current1 = poly1;
    do {
        Node* current2 = poly2;
        do {
            insertTerm(&result, current1->coefficient * current2->coefficient, current1->exponent + current2->exponent);
            current2 = current2->next;
        } while (current2 != poly2);
        current1 = current1->next;
    } while (current1 != poly1);
    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;
    int choice;

    do {
        printf("Polynomial Operations Menu:\n");
        printf("1. Input Polynomial 1\n");
        printf("2. Input Polynomial 2\n");
        printf("3. Subtract Polynomials\n");
        printf("4. Multiply Polynomials\n");
        printf("5. Display Result\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Polynomial 1:\n");
                int coeff, exp;
                printf("Enter coefficient (0 to exit): ");
                scanf("%d", &coeff);
                while (coeff != 0) {
                    printf("Enter exponent: ");
                    scanf("%d", &exp);
                    insertTerm(&poly1, coeff, exp);
                    printf("Enter coefficient (0 to exit): ");
                    scanf("%d", &coeff);
                }
                break;
            case 2:
                printf("Enter Polynomial 2:\n");
                printf("Enter coefficient (0 to exit): ");
                scanf("%d", &coeff);
                while (coeff != 0) {
                    printf("Enter exponent: ");
                    scanf("%d", &exp);
                    insertTerm(&poly2, coeff, exp);
                    printf("Enter coefficient (0 to exit): ");
                    scanf("%d", &coeff);
                }
                break;
            case 3:
                result = subtractPolynomials(poly1, poly2);
                printf("Polynomial subtraction complete.\n");
                break;
            case 4:
                result = multiplyPolynomials(poly1, poly2);
                printf("Polynomial multiplication complete.\n");
                break;
            case 5:
                printf("Resulting Polynomial: ");
                displayPoly(result);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    // Free memory
    Node* temp;
    while (poly1 != NULL) {
        temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
