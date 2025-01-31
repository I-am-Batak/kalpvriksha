//Time Complexity is O(1) for all the functions 
// Space Complexity is also O(1) as the array is static and doesn't change.

#include <stdio.h>
#include <stdlib.h>

void push(int *arr, int *topPointer) {
    int index = *topPointer;
    if (scanf("%d", &arr[index++]) == 1) {
        printf("%d successfully pushed to stack!\n", arr[index-1]);
        *topPointer = index;
        return;
    } else {
        printf("Invalid Input\n");
        getc(stdin);
        return;
    }
}

int isEmpty(int topPointer) {
    return topPointer == 0;
}

void pop(int *arr, int *topPointer) {
    if (isEmpty(*topPointer)) {
        printf("Stack is empty, cannot pop\n");
        return;
    } else {
        int index = --(*topPointer);
        printf("Popped %d from stack\n", arr[index]);
        return;
    }
}

void peek(int *arr, int topPointer) {
    if (isEmpty(topPointer)) {
        printf("Empty Stack\n");
        return;
    } else {
        printf("%d\n", arr[topPointer-1]);
    }
}

int main() {
    int stack[10001];
    int topPointer = 0;
    int option;

    while (1) {
        printf("1. Push to Stack\n2. Pop from Stack\n3. Peek top element\n4. Check if stack is empty\n5. Size of stack\n6. Exit\nYour Choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                push(stack, &topPointer);
                break;
            case 2:
                pop(stack, &topPointer);
                break;
            case 3:
                peek(stack, topPointer);
                break;
            case 4:
                if (isEmpty(topPointer)) {
                    printf("Empty stack\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("%d Elements in stack\n", topPointer);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice, try again!\n");
        }
    }
}
