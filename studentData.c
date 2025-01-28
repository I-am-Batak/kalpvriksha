#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[100];
    int roll_no;
    int attendance_percent;
    struct Student* next;
} Student;

Student* createNode(char* name, int roll_no, int attendance_percent) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    strcpy(newNode->name, name);
    newNode->roll_no = roll_no;
    newNode->attendance_percent = attendance_percent;
    newNode->next = NULL;
    return newNode;
}

void insertStudent(Student** head, char* name, int roll_no, int attendance_percent) {
    Student* newNode = createNode(name, roll_no, attendance_percent);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void bubbleSort(Student** head) {
    if (*head == NULL) return;

    Student *current, *index;
    int tempAttendance, tempRollNo;
    char tempName[100];
    int swapped;

    do {
        swapped = 0;
        current = *head;
        while (current != NULL && current->next != NULL) {
            index = current->next;
            if (current->attendance_percent < index->attendance_percent) {
                tempAttendance = current->attendance_percent;
                current->attendance_percent = index->attendance_percent;
                index->attendance_percent = tempAttendance;

                tempRollNo = current->roll_no;
                current->roll_no = index->roll_no;
                index->roll_no = tempRollNo;

                strcpy(tempName, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, tempName);

                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

void displayList(Student* head) {
    Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s, Roll No: %d, Attendance: %d%%\n", temp->name, temp->roll_no, temp->attendance_percent);
        temp = temp->next;
    }
}

void lowestAttendance(Student* head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }
    Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Student with highest attendance: Name: %s, Roll No: %d, Attendance: %d%%\n", temp->name, temp->roll_no, temp->attendance_percent);
}

void highestAttendance(Student* head) {
    if (head == NULL) {
        printf("No students in the list.\n");
        return;
    }
    printf("Student with lowest attendance: Name: %s, Roll No: %d, Attendance: %d%%\n", head->name, head->roll_no, head->attendance_percent);
}

void searchByName(Student* head, char* name) {
    Student* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Student found: Name: %s, Roll No: %d, Attendance: %d%%\n", temp->name, temp->roll_no, temp->attendance_percent);
            return;
        }
        temp = temp->next;
    }
    printf("Student with name %s not found.\n", name);
}

void searchByRollNo(Student* head, int roll_no) {
    Student* temp = head;
    while (temp != NULL) {
        if (temp->roll_no == roll_no) {
            printf("Student found: Name: %s, Roll No: %d, Attendance: %d%%\n", temp->name, temp->roll_no, temp->attendance_percent);
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d not found.\n", roll_no);
}

int main() {
    int n, roll_no, attendance_percent, option;
    char name[100];
    Student* head = NULL;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", name);
        printf("Roll No: ");
        scanf("%d", &roll_no);
        printf("Attendance Percent: ");
        scanf("%d", &attendance_percent);

        insertStudent(&head, name, roll_no, attendance_percent);
    }

    bubbleSort(&head);

    do {
        printf("\nMenu:\n");
        printf("1. Display the student with highest attendance\n");
        printf("2. Display the student with lowest attendance\n");
        printf("3. Search for a student by name\n");
        printf("4. Search for a student by roll number\n");
        printf("5. Display all students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                highestAttendance(head);
                break;
            case 2:
                lowestAttendance(head);
                break;
            case 3:
                printf("Enter student name to search: ");
                scanf(" %[^\n]", name);
                searchByName(head, name);
                break;
            case 4:
                printf("Enter roll number to search: ");
                scanf("%d", &roll_no);
                searchByRollNo(head, roll_no);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (option != 6);

    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
