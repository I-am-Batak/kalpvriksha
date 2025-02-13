#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial{
    int coefficient;
    int power;
    struct polynomial * next;    
}polynomial;

void addPolynomial(polynomial * head1, polynomial * head2) {
    polynomial * iterator1 = head1;
    polynomial * iterator2;

    while (iterator1 != NULL) {
        iterator2 = head2;
        while (iterator2 != NULL) {
            if (iterator1->power == iterator2->power) {
                int num = iterator1->coefficient + iterator2->coefficient;
                iterator1->coefficient = num;
            }
            iterator2 = iterator2->next;
        }
        iterator1 = iterator1->next;
    }
}

void printPolynomial(polynomial * head) {
    polynomial * iterator = head;
    while (iterator != NULL) {
        if(iterator->coefficient>0 && iterator->power>1)
        {
        printf("%dx^%d", iterator->coefficient, iterator->power);
        }
        else if(iterator->coefficient>0 && iterator->power==0){
            printf("%d",iterator->coefficient);
        }
        else if(iterator->coefficient>0 && iterator->power==1){
            printf("%dx",iterator->coefficient);
        }
        if (iterator->next != NULL && iterator->next->coefficient > 0) {
            printf(" + ");
        }
        iterator = iterator->next;
    }
    printf("\n");
}

void freeLinkedList(polynomial * head) {
    polynomial * temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void createLinkedList(polynomial ** head, int x, int y) {
    polynomial * newNode = (polynomial*)malloc(sizeof(polynomial));
    newNode->coefficient = x;
    newNode->power = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        polynomial * iterator = *head;
        while (iterator->next != NULL && iterator->power != y) {
            iterator = iterator->next;
        }
        if (iterator->power == y) {
            iterator->coefficient += x;
            free(newNode); // No need to add a new node, just update the existing one
        } else {
            iterator->next = newNode; // Add the new node at the end
        }
    }
}

int main() {
    int x, y;
    char c;
    printf("Enter Coefficient and power space separated of polynomial 1: ");
    polynomial * head1 = NULL;
    while (1) {
        scanf("%d %d%c", &x, &y, &c);
        createLinkedList(&head1, x, y);
        if (c == '\n') {
            break;
        }
    }

    printf("\nEnter Coefficient and power space separated of polynomial 2: ");
    polynomial * head2 = NULL;
    while (1) {
        scanf("%d %d%c", &x, &y, &c);
        createLinkedList(&head2, x, y);
        if (c == '\n') {
            break;
        }
    }

    addPolynomial(head1, head2);
    printPolynomial(head1);

    freeLinkedList(head1);
    freeLinkedList(head2);

    return 0;
}
