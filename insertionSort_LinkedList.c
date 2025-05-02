#include <stdlib.h>
#include <stdio.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void generateDoubleLinkedList(struct node **head){
    int n;
    printf("Enter Number of Elements:");
    scanf("%d",&n);
    struct node *prev_node=NULL;
    for(int i=0;i<n;i++){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        printf("Enter %d element:",i+1);
        scanf("%d",&new_node->data);
        new_node->next=NULL;
        new_node->prev=prev_node;
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

void insertionSortList(struct node **head) {
    if (*head == NULL || (*head)->next == NULL) return;

    struct node *iterator1 = (*head)->next;

    while (iterator1 != NULL) {
        struct node *iterator2 = iterator1->prev;
        
        while (iterator2 != NULL && iterator2->data > iterator1->data) {
            iterator2 = iterator2->prev;
        }
        if (iterator2 != iterator1->prev) {
            if (iterator1->next != NULL) {
                iterator1->next->prev = iterator1->prev;
            }
            if (iterator1->prev != NULL) {
                iterator1->prev->next = iterator1->next;
            }
            if (iterator2 == NULL) {
                iterator1->next = *head;
                (*head)->prev = iterator1;
                iterator1->prev = NULL;
                *head = iterator1;
            } else {
                iterator1->prev = iterator2;
                iterator1->next = iterator2->next;
                if (iterator2->next != NULL) {
                    iterator2->next->prev = iterator1;
                }
                iterator2->next = iterator1;
            }
        }
        iterator1 = iterator1->next;
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
    generateDoubleLinkedList(&head);
    printf("Linked List:");
    printLinkedList(head);
    insertionSortList(&head);
    printf("Sorted Linked List:");
    printLinkedList(head);
    freeLinkedList(head);
    return 0;
}