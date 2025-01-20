#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertAtEnd(struct node **head,int i){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=i;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    else{
        struct node* pos=*head;
        while(pos->next!=NULL){
            pos=pos->next;
        }
        pos->next=newNode;
    }
}
void insertAtBeginning(struct node **head,int i){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=i;
    newNode->next=*head;
    *head=newNode;
}
void insertAtPosition(struct node **head,int i,int pos){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=i;
    struct node* current=*head;
    int count=1;
    if(pos==1){
        newNode->next=*head;
        *head=newNode;
        return;
    }
    while(current!=NULL && count<pos-1){
        current=current->next;
        count++;
    }
    if(current==NULL){
        printf("Out of bounds!\n");
        free(newNode);
        return;
    }
    newNode->next=current->next;
    current->next=newNode;
}

void display(struct node *head){
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void updateAtPosition(struct node *head,int i,int pos){
    if(head==NULL){
        printf("Empty List");
        return;
    }
    struct node* current=head;
    int count=1;
    while(current!=NULL && count<pos){
        current=current->next;
        count++;
    }
    if(current==NULL){
        printf("Out of Bounds!\n");
        return;
    }
    current->data=i;
}
void deleteAtBeginning(struct node **head){
    if(*head==NULL){
        printf("Empty List!\n");
    }
    struct node* deletedNode=*head;
    *head=(*head)->next;
    free(deletedNode);
}
void deleteAtEnd(struct node **head){
    if(*head==NULL){
        printf("Empty List!\n");
    }
    struct node*current=*head;
    if(current->next==NULL){
        free(current);
        *head=NULL;
        return;
    }
    while(current->next!=NULL && current->next->next!=NULL){
        current=current->next;
    }
    struct node* deleteNode=current->next;
    current->next=NULL;
    free(deleteNode);
}
void deleteAtPosition(struct node **head,int pos){
    if(*head==NULL){
        printf("Empty list\n");
        return;
    }
    struct node* current=*head;
    if(pos==1){
        *head=current->next;
        free(current);
        return;
    }
    int count=1;
    while(current!=NULL && count<pos-1){
        current=current->next;
        count++;
        
    }
    if(current==NULL || current->next==NULL){
        printf("Out of Bounds\n");
        return;
    }
    struct node* deleteNode=current->next;
    current->next=current->next->next;
    free(deleteNode);
}

int main(){
    struct node *head=NULL, *newNode, *tail;
    int n,choice;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&choice);
        if(choice==1){
            int i;
            scanf("%d",&i);
            insertAtEnd(&head,i);
        }
        else if(choice==2){
            int i;
            scanf("%d",&i);
            insertAtBeginning(&head,i);
        }
        else if(choice==3){
            int pos;
            scanf("%d",&pos);
            int i;
            scanf("%d",&i);
            insertAtPosition(&head,i,pos);
        }
        else if(choice==4){
            display(head);
        }
        else if(choice==5){
            int pos;
            scanf("%d",&pos);
            int i;
            scanf("%d",&i);
            updateAtPosition(head,i,pos);
        }
        else if(choice==6){
            deleteAtBeginning(&head);
        }
        else if(choice==7){
            deleteAtEnd(&head);
        }
        else if(choice==8){
            int pos;
            scanf("%d",&pos);
            deleteAtPosition(&head,pos);
        }
        else{
            printf("Invalid choice!\n exit!");
        }
    }
}