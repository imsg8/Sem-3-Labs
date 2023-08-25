#include <stdio.h>
#include <stdlib.h>

// Function to demonstrate passing a pointer to a function
void modifyValue(int *numPtr) {
    *numPtr += 10;
}

// Function to demonstrate returning a pointer from a function
int *createAndInitArray(int size, int value) {
    int *arr = (int *)malloc(size * sizeof(int));

    if (arr != NULL) {
        for (int i = 0; i < size; i++) {
            arr[i] = value;
        }
    }

    return arr;
}

// Function to demonstrate using pointer to pointer
void updatePointerValue(int **ptrPtr) {
    int newVal = 999;
    *ptrPtr = &newVal;
}

int main() {
    // Demonstrate passing pointers to a function
    int num = 5;
    printf("Original value of num: %d\n", num);
    modifyValue(&num);
    printf("Value of num after modification: %d\n", num);

    // Demonstrate returning a pointer from a function
    int size = 5;
    int value = 42;
    int *arr = createAndInitArray(size, value);

    if (arr != NULL) {
        printf("Array elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    }

    // Demonstrate using pointer to pointer
    int valueToUpdate = 123;
    int *ptr = &valueToUpdate;
    int **ptrToPtr = &ptr;

    printf("Value before update: %d\n", **ptrToPtr);
    updatePointerValue(ptrToPtr);
    printf("Value after update: %d\n", **ptrToPtr);

    return 0;
}