// Time Complexity is O(1) for all the functions of queue
// The freeLinkedList which is not a part of queue operation has a time complexity of O(n) for freeing all nodes
// The Space Complexity is O(n) as there is no cap on the number of nodes this can have so as the number of nodes grow space complexity grows

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void enqueue(struct node **head,struct node **tail,int *length){
    int num;
    if(scanf("%d",&num)==1){
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        newNode->data=num;
        newNode->next=NULL;
        (*length)++;
        if(*head==NULL){
            *head=newNode;
        }
        else{
            (*tail)->next=newNode;
        }
        *tail=newNode;
        printf("%d enqueued to queue succesfully!\n",num);
    }
    else{
        printf("Invalid input\n");
        while (getchar() != '\n');
    }
}

int isEmpty(int length){
    if(length==0){
        return 1;
    }
    else{
        return 0;
    }
}

void dequeue(struct node **head,int *length){
    if(isEmpty(*length)){
        printf("No elements to dequeue\n");
    }
    else{
        struct node* temp=*head;
        *head=temp->next;
        printf("%d dequeud\n",temp->data);
        free(temp);
        (*length)--;
    }
}

void peek(struct node* head,int length){
    if(isEmpty(length)){
        printf("No elements in the stack\n");
    }
    else{
        printf("%d is at the front\n",head->data);
    }
}

void freeLinkedList(struct node *head){
    struct node* current=head;
    while(current!=NULL){
        struct node* temp=current;
        current=current->next;
        free(temp);
    }
}

int main(){
    struct node*head=NULL;
    struct node*tail=NULL;
    int option;
    int length=0;
     while(1){
    printf("1. enqueue to queue\n2. dequeue from queue\n3. Peek front most element\n4. Check if queue is empty\n5. Size of queue\n6. Exit\nYour Choice: ");
    scanf("%d",&option);
    switch (option){
        case 1:
        enqueue(&head,&tail,&length);
        break;
        case 2:
        dequeue(&head,&length);
        break;
        case 3:
        peek(head,length);
        break;
        case 4:
        if(isEmpty(length)){
            printf("The queue is empty\n");
        }
        else{
            printf("The queue is not empty\n");
        }
        break;
        case 5:
        printf("%d elements in the queue\n", length);
        break;
        case 6:
        freeLinkedList(head);
        return 0;
        default:
        printf("Invalid choice!\n");
        break;
    }
    }
}