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

void reorder(node * head,int len){
    node * iterator=head;
    int i=1;
    while(iterator!=NULL){
        if(i%2==1){
            node * iterator2=iterator;
            if(iterator2->next==NULL || iterator2->next->next==NULL){
                break;
            }
            while(iterator2->next->next!=NULL){
                iterator2=iterator2->next;
            }
            iterator2->next->next=iterator->next;
            iterator->next=iterator2->next;
            iterator2->next=NULL;
        }
        i++;
        if(iterator->next!=NULL){
        iterator=iterator->next;
        }
    }
}

int main() {
    char str1[100];
    node *head1 = NULL;
    int len=0;
    printf("sample input: 2->3->4->...\n");
    printf("Enter linked list: ");
    scanf("%[^\n]", str1);
    getchar();
    char *token = strtok(str1, "->");
    while (token != NULL) {
        int n = atoi(token);
        createLinkedList(&head1, n);
        len++;
        token = strtok(NULL, "->");
    }
    reorder(head1,len);
    printf("Reordered: ");
    print(head1);
    freeLinkedList(head1);
    return 0;
}
