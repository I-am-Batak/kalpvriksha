#include <stdlib.h>
#include <stdio.h>

int stringLength(char string[]){
    int length=0;
    int i=0;
    while(string[i]!='\0'){
        length++;
        i++;
    }
    return length;
}

void removeDuplicates(char string[],int length){

    for(int i=1;i<length;i++){
        for(int j=0;j<i;j++){
            if(string[i]==string[j]){
                string[i]=" ";
            }
        }
    }
}

int main(){
    printf("Enter a String: ");
    char inputString[50];
    scanf("%s",&inputString);
    int length=stringLength(inputString);
    char resultString[50]="";
    removeDuplicates(inputString,length);
    printf("String without Duplicates :%s",inputString);

}