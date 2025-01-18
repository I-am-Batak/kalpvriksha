#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void adduser();
void showusers();
void changeuser();
void removeuser();

int main() {
    int option;
    while (1) {
        printf("\nSimple User Manager\n");
        printf("1. Add User\n");
        printf("2. Show Users\n");
        printf("3. Change User\n");
        printf("4. Remove User\n");
        printf("5. Quit\n");
        printf("Pick an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                adduser();
                break;
            case 2:
                showusers();
                break;
            case 3:
                changeuser();
                break;
            case 4:
                removeuser();
                break;
            case 5:
                printf("Exiting!\n");
                return 0; 
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}

void adduser() {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    int id;
    char name[100];
    int age;
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Name: ");
    scanf(" %[^\n]s", name); 
    printf("Enter Age: ");
    scanf("%d", &age);
    fprintf(file, "[id:%d, name:%s, age:%d]\n", id, name, age);
    fclose(file);
    printf("User added!\n");
}

void showusers() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }
    char line[200];
    printf("\nUsers:\n");
    while (fgets(line, sizeof(line), file)) {
        int id, age;
        char name[100];
        if (sscanf(line, "[id:%d, name:%99[^,], age:%d]", &id, name, &age) == 3) {
            printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
        }
    }
    fclose(file);
}
void changeuser() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }
    int id, newage, found = 0;
    char newname[100];
    printf("Enter ID to change: ");
    scanf("%d", &id);
    FILE *tempfile = fopen("tempfile", "w");
    if (tempfile == NULL) {
        printf("Error opening tempfile.\n");
        fclose(file);
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        int tempid, tempage;
        char tempname[100];
        if (sscanf(line, "[id:%d, name:%99[^,], age:%d]", &tempid, tempname, &tempage) == 3) {
            if (tempid == id) {
                found = 1;
                printf("Enter new Name: ");
                scanf(" %[^\n]s", newname); 
                printf("Enter new Age: ");
                scanf("%d", &newage);
                fprintf(tempfile, "[id:%d, name:%s, age:%d]\n", id, newname, newage);
            } else {
                fprintf(tempfile, "%s", line);
            }
        }
    }
    fclose(file);
    fclose(tempfile);
    if (found) {
        remove("users.txt");
        rename("tempfile", "users.txt");
        printf("User changed!\n");
    } else {
        remove("tempfile");
        printf("User not found.\n");
    }
}

void removeuser() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("No users found.\n");
        return;
    }
    int id, found = 0;
    printf("Enter ID to remove: ");
    scanf("%d", &id);
    FILE *tempfile = fopen("tempfile", "w");
    if (tempfile == NULL) {
        printf("Error opening tempfile.\n");
        fclose(file);
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        int tempid;
        char tempname[100];
        int tempage;
        if (sscanf(line, "[id:%d, name:%99[^,], age:%d]", &tempid, tempname, &tempage) == 3) {
            if (tempid != id) {
                fprintf(tempfile, "%s", line);
            } else {
                found = 1;
            }
        }
    }
    fclose(file);
    fclose(tempfile);
    if (found) {
        remove("users.txt");
        rename("tempfile", "users.txt");
        printf("User removed!\n");
    } else {
        remove("tempfile");
        printf("User not found.\n");
    }
}
