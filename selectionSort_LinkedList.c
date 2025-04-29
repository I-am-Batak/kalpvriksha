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

void selectionSortList(struct node *head){
    struct node* current=head;
    struct node* iterator=NULL;
    struct node*swapAddress=NULL;
    while(current!=NULL){
        iterator=current->next;
        swapAddress=current;
        while(iterator!=NULL){
            if(swapAddress->data>iterator->data){
                swapAddress=iterator;
            }
            iterator=iterator->next;
        }
        if(swapAddress!=current){
        int temp=current->data;
        current->data=swapAddress->data;
        swapAddress->data=temp;
        }
        current=current->next;
    }
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
    selectionSortList(head);
    printf("Sorted Linked List:");
    printLinkedList(head);
    freeLinkedList(head);
    return 0;
}