//Time Complexity for pop and push is O(n)
//Space Complexity is O(1) as we define max globally

#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

int isEmpty(int size) {
    return size == 0;
}

void enqueue(int *arr, int *size, int num) {
    if (*size >= MAX) {
        printf("Queue overflow\n");
        return;
    }
    arr[0] = num;
    (*size)++;
}

int pop(int *arr, int *size) {
    if (*size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int popped = arr[0];
    for (int i = 0; i < (*size) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    return popped;
}

void push(int *arr, int *size, int num) {
    int queue2[MAX];
    enqueue(queue2, size, num);
    printf("%d Pushed Succesfully\n",num);

    for(int i=0;i<(*size)-1;i++){
        queue2[i+1]=arr[i];
    }
    for(int i=0;i<(*size);i++){
        arr[i]=queue2[i];
    }
    
}

void peek(int *arr, int size) {
    if (size > 0) {
        printf("The element at top is %d\n", arr[0]);
    } else {
        printf("Stack is empty\n");
    }
}

int main() {
    int queue[MAX];
    int size = 0;
    int option;
    int num;

    while (1) {
        printf("1. Push to Stack\n2. Pop from Stack\n3. Peek top element\n4. Check if stack is empty\n5. Size of stack\n6. Exit\nYour Choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a number to push: ");
                if (scanf("%d", &num) == 1) {
                    push(queue, &size, num);
                } else {
                    printf("Invalid input\n");
                    while (getchar() != '\n');
                }
                break;
            case 2:
                if (isEmpty(size)) {
                    printf("Stack is empty\n");
                } else {
                    int popped = pop(queue, &size);
                    printf("Popped element: %d\n", popped);
                }
                break;
            case 3:
                peek(queue, size);
                break;
            case 4:
                if (isEmpty(size)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Size of stack: %d\n", size);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }

    return 0;
}
