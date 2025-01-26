#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

void generateLinkedList(struct node **head){
    int n;
    printf("Enter Number of Elements:");
    scanf("%d",&n);
    struct node *prev_node=NULL;
    for(int i=0;i<n;i++){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter %d element:",i+1);
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        if(*head==NULL){
            *head=new_node;
            prev_node=new_node;
        }
        else{
            prev_node->next=new_node;
            prev_node=new_node;
        }
    }
}

void printLinkedList(struct node * head){
    struct node *current=head;
    while(current!=NULL){
        printf("%d",current->data);
        if(current->next!=NULL){
            printf("->");
        }
        current=current->next;
    }
    printf("\n");
}

void bubbleSortList(struct node *head){
    int swapped;
    if(head==NULL){return;}
    struct node *iterator=head;
    do{
        swapped=0;
        iterator=head;
        while(iterator->next!=NULL){
            if(iterator->data>iterator->next->data){
                int temp=iterator->data;
                iterator->data=iterator->next->data;
                iterator->next->data=temp;
                swapped=1;
            }
            iterator=iterator->next;
        }
    }
    while(swapped);
}
void freeLinkedList(struct node *head) {
    struct node *current = head;
    struct node *next_node;
    
    while (current != NULL) {
        next_node = current->next;  
        free(current);               
        current = next_node;
    }
}

int main(){
    struct node *head=NULL;
    generateLinkedList(&head);
    printf("Linked List:");
    printLinkedList(head);
    bubbleSortList(head);
    printf("Sorted Linked List:");
    printLinkedList(head);
    freeLinkedList(head);
    return 0;
}