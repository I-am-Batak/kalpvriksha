// Time Complexity is O(1) for all the functions of stack
// The freeLinkedList which is not a part of stack operation has a time complexity of O(n) for freeing all nodes
// The Space Complexity is O(n) as there is no cap on the number of nodes this can have so as the number of nodes grow space complexity grows
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*next;
};

void push(struct node **head,int *length){
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
            newNode->next=*head;
            *head=newNode;
        }
        printf("%d pushed to stack succesfully!\n",num);
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

void pop(struct node **head,int *length){
    if(isEmpty(*length)){
        printf("No elements to pop\n");
    }
    else{
        struct node* temp=*head;
        *head=temp->next;
        printf("%d Popped\n",temp->data);
        free(temp);
        (*length)--;
    }

}

void peek(struct node* head,int length){
    if(isEmpty(length)){
        printf("No elements in the stack\n");
    }
    else{
        printf("%d is at top\n",head->data);
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
    int option;
    int length=0;
     while(1){
    printf("1.Push to Stack\n2.Pop from stack\n3.Peek top Element\n4.Check if stack is empty\n5.Size of Stack\n6.Exit\nYour choice:");
    scanf("%d",&option);
    switch (option){
        case 1:
        push(&head,&length);
        break;
        case 2:
        pop(&head,&length);
        break;
        case 3:
        peek(head,length);
        break;
        case 4:
        if(isEmpty(length)){
            printf("The stack is empty\n");
        }
        else{
            printf("The stack is not empty\n");
        }
        break;
        case 5:
        printf("%d elements in the stack\n", length);
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