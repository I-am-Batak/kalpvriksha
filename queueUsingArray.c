#include <stdio.h>
#include <stdlib.h>

void enqueue(int *arr,int *entryPoint){
    int index = *entryPoint;
    if (scanf("%d", &arr[index++]) == 1) {
        printf("%d successfully enqueued to queue!\n", arr[index-1]);
        *entryPoint = index;
        return;
    } else {
        printf("Invalid Input\n");
        getc(stdin);
        return;
    }
}

int isEmpty(int lastPos,int firstPos){
    return lastPos-firstPos==0;
}

int dequeue(int *arr,int *exitPoint){
    int index=*exitPoint;
    int result=arr[index++];
    *exitPoint=index;
    return result;

}
void peek(int *arr,int exitPoint){
    printf("%d is at exit!\n",arr[exitPoint]);
    return;
}

int main() {
    int queue[10001];
    int exitPointer = 0;
    int entrypointer = 0;
    int option;
    int temp;

    while (1) {
        printf("1. enqueue to queue\n2. dequeue from queue\n3. Peek front most element\n4. Check if queue is empty\n5. Size of queue\n6. Exit\nYour Choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                enqueue(queue,&entrypointer);
                break;
            case 2:
                if(isEmpty(entrypointer,exitPointer)){
                    printf("The queue is empty\n");
                }
                else{

                temp=dequeue(queue, &exitPointer);
                printf("%d is the dequeued element\n",temp);
                }
                break;
            case 3:
            if(isEmpty(entrypointer,exitPointer)){
                    printf("The queue is empty\n");
                }
                else{
                peek(queue, exitPointer);
                }
                break;
            case 4:
                if (isEmpty(entrypointer,exitPointer)) {
                    printf("Empty queue\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("%d Elements in queue\n", entrypointer-exitPointer);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice, try again!\n");
                break;
        }
    }
}