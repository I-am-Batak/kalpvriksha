#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void push(int *arr, int *topPointer, int num) {
    int index = (*topPointer);
    arr[index++] = num;
    *topPointer = index;
    return;
}

int isEmpty(int topPointer) {
    return topPointer == 0;
}

int pop(int *arr, int *topPointer) {
    int index = --(*topPointer);
    return arr[index];
}

int dequeue(int *arr, int *topPointer) {
    int stack2[MAX];
    int topPointer2 = 0;
    while (*topPointer > 0) {
        int temp = pop(arr, topPointer);
        push(stack2, &topPointer2, temp);
    }
    int result = pop(stack2, &topPointer2);
    while (topPointer2 > 0) {
        int temp = pop(stack2, &topPointer2);
        push(arr, topPointer, temp);
    }

    return result;
}

void peek(int *arr, int topPointer) {
    if (isEmpty(topPointer)) {
        printf("Empty Stack\n");
        return;
    } else {
        printf("%d\n", arr[topPointer - 1]);
    }
}

int main() {
    int stack[MAX];
    int topPointer = 0;
    int option;
    int num;
    while (1) {
        printf("1. Push to Stack\n2. Pop from Stack\n3. Peek top element\n4. Check if stack is empty\n5. Size of stack\n6. Exit\nYour Choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (scanf("%d", &num) == 1) {
                    push(stack, &topPointer, num);
                } else {
                    printf("Invalid Input\n");
                    getc(stdin);
                }
                break;
            case 2:
                num = dequeue(stack, &topPointer);
                printf("The dequeued element is: %d\n", num);
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
