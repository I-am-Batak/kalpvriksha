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

void reverselist(node *head, node *tail, int k) {
    printf("Reversing list from %d to %d with length k=%d\n", head->n, tail->n, k);

    node *current = head;
    node *last = tail;
    
    int mid = k / 2;
    
    for (int i = 0; i < mid; i++) {
        int temp = current->n;
        current->n = last->n;
        last->n = temp;

        current = current->next;
        
        node *temp_node = head;
        for (int j = 0; j < k - i - 2; j++) {
            temp_node = temp_node->next;
        }
        last = temp_node;
    }
}

void selectKgroup(node * head,int k){
    printf("1.\n");
    node * iterator=head;
    int currk=1;
    node * tempHead;
    node * tempTail;
    while(iterator!=NULL){
        printf("2.\n");
        if(currk==1){
            printf("2.1\n");
            tempHead=iterator;
        }
        if(currk==k){
            printf("2.2\n");
            tempTail=iterator;
            reverselist(tempHead,tempTail,k);
            currk=0;
        }
        iterator=iterator->next;
        currk++;
    }
}

int main() {
    char str1[100];
    node *head1 = NULL;
    int len=0;
    int k;
    printf("sample input: 2->3->4->...\n");
    printf("Enter linked list: ");
    scanf("%[^\n]", str1);
    getchar();
    scanf("%d",&k);
    char *token = strtok(str1, "->");
    while (token != NULL) {
        int n = atoi(token);
        createLinkedList(&head1, n);
        len++;
        token = strtok(NULL, "->");
    }
    if(k>len){
        print(head1);
    }
    else{
    selectKgroup(head1,k);
    printf("Reordered: ");
    print(head1);
    }
    freeLinkedList(head1);
    return 0;
}
