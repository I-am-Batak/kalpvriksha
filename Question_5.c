#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int n;
    struct node *next;
} node;

void createLinkedList(node **head, int x) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->n = x;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        node *iterator = *head;
        while (iterator->next != NULL) {
            iterator = iterator->next;
        }
        iterator->next = newNode;
    }
}

void print(node *head) {
    node *iterator = head;
    while (iterator != NULL) {
        printf("%d", iterator->n);
        if (iterator->next != NULL) {
            printf("->");
        }
        iterator = iterator->next;
    }
    printf("\n");
}

void freeLinkedList(node *head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void merge(node ** head1,node ** head2,node ** head3){
    node * iterator1=(*head1);
    node * iterator2=(*head2);
    int n;
    while(iterator1!=NULL || iterator2!=NULL){
        if(iterator1!=NULL && iterator2!=NULL){
            if(iterator1->n>+iterator2->n){
                n=iterator2->n;
                createLinkedList(head3,n);
                iterator2=iterator2->next;
            }
            else{
                n=iterator1->n;
                createLinkedList(head3,n);
                iterator1=iterator1->next;
            }
        }
        if(iterator1==NULL && iterator2!=NULL){
            n=iterator2->n;
            createLinkedList(head3,n);
            iterator2=iterator2->next;
            
        }
        if(iterator2==NULL && iterator1!=NULL){
            n=iterator1->n;
            createLinkedList(head3,n);
            iterator1=iterator1->next;
        }
    }
}
int main() {
    char str1[100];
    char str2[100];
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    int lenNum2=0;
    printf("sample input: 2->3->4->...\n");
    printf("Enter 1st linked list: ");
    scanf("%[^\n]", str1);
    getchar();
    printf("Enter 2nd linked list: ");
    scanf("%[^\n]", str2);
    getchar(); 
    char *token = strtok(str1, "->");
    while (token != NULL) {
        int n = atoi(token);
        createLinkedList(&head1, n);
        token = strtok(NULL, "->");
    }
    token = strtok(str2, "->");
    while (token != NULL) {
        int n = atoi(token);
        createLinkedList(&head2, n);
        token = strtok(NULL, "->");
    }
    merge(&head1,&head2,&head3);
    printf("Result: ");
    print(head3);
    freeLinkedList(head1);
    freeLinkedList(head2);
    freeLinkedList(head3);

    return 0;
}
