#include <stdio.h>
#include <stdlib.h>
#define table_size 10

struct hashNode{
    int key;
    int value;
    struct hashNode * next;
};

struct pointer{
    struct hashNode * head;
};

struct pointer * hashtable[table_size];

int hash(int key){
    int index = key % table_size;
    return index;
}

void initHashTable() {
    for (int i = 0; i < table_size; i++) {
        hashtable[i] = (struct pointer*)malloc(sizeof(struct pointer));
        if (hashtable[i] == NULL) {
            printf("Memory Allocation failed\n");
            exit(1);
        }
        hashtable[i]->head = NULL;
    }
}

void add() {
    struct hashNode *newNode = (struct hashNode*)malloc(sizeof(struct hashNode));
    if (newNode == NULL) {
        printf("Memory Allocation failed\n");
        return;
    }
    printf("Enter Key: ");
    if(scanf("%d", &newNode->key)<1){
        printf("Invalid input\n");
        return;
    };
    printf("Enter Value: ");
    if(scanf("%d", &newNode->value)<1){
        printf("Invalid Input\n");
    }
    newNode->next = NULL;

    int index = hash(newNode->key);
    printf("2. hashed key = %d\n", index);
    
    if (hashtable[index]->head == NULL) {
        hashtable[index]->head = newNode;
    } else {
        struct hashNode *current = hashtable[index]->head;
        while (current != NULL) {
            if (current->key == newNode->key) {
                current->value = newNode->value;
                free(newNode);
                return;
            }
            if (current->next == NULL) break;
            current = current->next;
        }
        current->next = newNode;
    }
    printf("2. %d:%d inserted successfully\n", newNode->key, newNode->value);
}

void delete() {
    int targetKey;
    printf("Enter key for deletion: ");
    scanf("%d", &targetKey);
    int index = hash(targetKey);

    if (hashtable[index]->head == NULL) {
        printf("No elements found at index %d\n", index);
        return;
    }

    if (hashtable[index]->head->key == targetKey) {
        struct hashNode *temp = hashtable[index]->head;
        hashtable[index]->head = hashtable[index]->head->next;
        printf("%d:%d Deleted\n", temp->key, temp->value);
        free(temp);
    } else {
        struct hashNode *current = hashtable[index]->head;
        struct hashNode *prev = NULL;
        while (current != NULL) {
            if (current->key == targetKey) {
                prev->next = current->next;
                printf("%d:%d Deleted\n", current->key, current->value);
                free(current);
                return;
            }
            prev = current;
            current = current->next;
        }
        printf("Key %d not found for deletion.\n", targetKey);
    }
}

void search() {
    int targetKey;
    printf("Enter key for searching: ");
    scanf("%d", &targetKey);
    int index = hash(targetKey);
    
    struct hashNode *current = hashtable[index]->head;
    while (current != NULL) {
        if (current->key == targetKey) {
            printf("Found %d:%d\n", current->key, current->value);
            return;
        }
        current = current->next;
    }
    printf("Key %d not found.\n", targetKey);
}

void display() {
    for (int i = 0; i < table_size; i++) {
        struct hashNode *current = hashtable[i]->head;
        if (current == NULL) {
            continue;
        } else{
             printf("Index %d -> ", i);
            while (current != NULL) {
                printf("(%d:%d)", current->key, current->value);
                current = current->next;
                if (current != NULL) {
                    printf(" -> ");
                } else {
                    printf("\n");
                }
            }
        }
    }
}

void freeHashTable() {
    for (int i = 0; i < table_size; i++) {
        struct hashNode *current = hashtable[i]->head;
        while (current != NULL) {
            struct hashNode *temp = current;
            current = current->next;
            free(temp);
        }
        free(hashtable[i]);
    }
}

int main() {
    initHashTable();

    int choice;
    while (1) {
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nYour choice: ");
        if(scanf("%d", &choice)==1)
        {
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                search();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                freeHashTable();
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid Choice! Try Again!\n");
        }
        }
        else{
        printf("Invalid Input! Try again!\n");
        }
        while(getchar()!='\n');
    }
}
