#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

int Smallest(int *arr, int size) {
    int smallest = *arr; // Initialize with the first element

    for (int i = 1; i < size; i++) {
        if (*(arr + i) < smallest) {
            smallest = *(arr + i);
        }
    }

    return smallest;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int)); // Dynamically allocate memory

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int smallest = Smallest(arr, size);

    printf("The smallest element in the array is: %d\n", smallest);

    free(arr); // Free dynamically allocated memory

    return 0;
}