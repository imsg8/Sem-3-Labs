#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 15
struct STACK{
    char data[max];
    int top;
};
void initialize(struct STACK *stk){
    stk->top = -1;
}
int isem(struct STACK *stk){
    return (stk->top == -1);
}
char push(struct STACK *stk, char ele){
    if(stk->top == max - 1){
        printf("Overflow");
        return 1;
    }
    stk->data[++stk->top] = ele;
}
char pop(struct STACK *stk){
    if(isem(stk)){
        printf("Nothing to pop");
    }
    char data = stk->data[stk->top];
    stk->top--;
    return data;
}
void display(struct STACK *stk) {
    if (isem(stk)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents: ");
    for (int i = 0; i <= stk->top; i++) {
        printf("%c ", stk->data[i]);
    }
    printf("\n");
}

int main(){;
    struct STACK stk;
    int choice;
    char item;
    do{
    printf("Enter choice -\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter a character to push onto the stack: ");
                fflush(stdin);
                scanf("%c", &item);
                push(&stk,item);
                break;
            case 2:
                item = pop(&stk);
                if (item != '\0') {
                    printf("Popped '%c' from the stack.\n", item);
                }
                break;
            case 3:
                display(&stk);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 4);
}