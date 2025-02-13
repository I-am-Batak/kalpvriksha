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

void sumNumbers(node ** head1, node**head2,node **head3){
    node * iterator1=(*head1);
    node *iterator2=(*head2);
    int carry=0;
    int num;
    while(iterator1!=NULL || iterator2!=NULL||carry!=0){
        int n1=iterator1!=NULL?iterator1->n:0;
        int n2=iterator2!=NULL?iterator2->n:0;
        num=n1+n2+carry;
        carry=num>=10?1:0;
        createLinkedList(head3,num%10);
        if(iterator1!=NULL){
            iterator1=iterator1->next;
        }
        if(iterator2!=NULL){
            iterator2=iterator2->next;
        }
    }
}

int main() {
    char str1[100];
    char str2[100];
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;

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
    sumNumbers(&head1,&head2,&head3);
    printf("Result: ");
    print(head3);
    freeLinkedList(head1);
    freeLinkedList(head2);

    return 0;
}
