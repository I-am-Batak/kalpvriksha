#include <stdio.h>
#include <stdlib.h>

struct patient{
    int patient_id;
    int orderOfEntry;
    int severity;
    struct patient * next;
};

void registerPatient(int n,struct patient **head,struct patient ** tail){
    int id;
    char severity[10];
    for(int i=0;i<n;i++){
        scanf("%d",&id);
        scanf("%s",severity);
        struct patient * newPatient=(struct patient *)malloc(sizeof(struct patient));
        newPatient->patient_id=id;
        newPatient->orderOfEntry=i+1;
        if(severity=="Critical"){
            newPatient->severity=3;
        }
        else if(severity=="Serious"){
            newPatient->severity=2;
        }
        else{
            newPatient->severity=1;
        }
        if(*head==NULL){
            *head=newPatient;
            newPatient->next=NULL;
            *tail=newPatient;
        }
        else{
            (*tail)->next=newPatient;
            (*tail)=newPatient;
            newPatient->next=NULL;
        }
    }
}

void sortList(struct patient ** head){
    struct patient * critical=NULL;
    struct patient * criticalHead=NULL;
    struct patient * serious=NULL;
    struct patient * seriousHead=NULL;
    struct patient * iterator=*head;
    int swapped=1;
    while(iterator!=NULL){
        if(iterator->next->severity==3){
            if(critical==NULL){
                critical=iterator->next;
                critical->orderOfEntry=iterator->next->orderOfEntry;
                critical->patient_id=iterator->next->patient_id;
                critical->severity=iterator->next->severity;
                criticalHead=critical;
            }
            else{
                critical->next=iterator->next;
                critical->orderOfEntry=iterator->next->orderOfEntry;
                critical->patient_id=iterator->next->patient_id;
                critical->severity=iterator->next->severity;
            }
            struct patient * temp=iterator->next;
            iterator->next=iterator->next->next;
            free(temp);
        }
        else if(iterator->next->severity==2){
            if(serious==NULL){
                serious=iterator->next;
                seriousHead=serious;
                serious->orderOfEntry=iterator->next->orderOfEntry;
                serious->patient_id=iterator->next->patient_id;
                serious->severity=iterator->next->severity;
            }
            else{
                serious->next=iterator->next;
                serious->orderOfEntry=iterator->next->orderOfEntry;
                serious->patient_id=iterator->next->patient_id;
                serious->severity=iterator->next->severity;
            }
            struct patient * temp=iterator->next;
            iterator->next=iterator->next->next;
            free(temp);
        }
        iterator=iterator->next;
    }
    critical->next=seriousHead;
    serious->next=*head;
    *head=criticalHead;
    free(critical);
    free(criticalHead);
    free(serious);
    free(seriousHead);
    free(iterator);
}

void printLinkedList(struct patient * head){
    struct patient *current=head;
    while(current!=NULL){
        if(current->severity=3){
            printf("%d Critical\n",current->patient_id);
        }
        else if(current->severity=2){
            printf("%d Serious\n",current->patient_id);
        }
        else{
            printf("%d Stable\n",current->patient_id);
        }
        current=current->next;
    }
}
void freeLinkedList(struct patient * head){
    struct patient *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    struct patient *head=NULL;
    struct patient *tail=NULL;
    registerPatient(n,&head,&tail);
    printf("1\n");
    sortList(&head);
    printf("2\n");
    printLinkedList(head);
    printf("3\n");
    freeLinkedList(head);
    printf("4\n");
    return 0;
}