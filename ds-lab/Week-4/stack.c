#include <stdio.h>
void deleteKSmallerElements(int arr[], int n, int k) {
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top != -1 && k > 0 && arr[i] > stack[top]) {
            top--;
            k--;
        }
            stack[++top] = arr[i];
    }

    while (k > 0 && top >= 0) {
        top--;
        k--;
    }

    for (int i = 0; i <= top; i++) {
        printf("%d \t \n", stack[i]);
    }
}

int main() {
    int arr[10], n, k;
    printf("Enter the size of array - ");
    scanf("%d",&n);
    printf("\nEnter elements - ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("---------------------------------------");
    printf("\nEnter number of elements to delete - ");
    scanf("%d",&k);
    deleteKSmallerElements(arr, n, k);
    return 0;
}
