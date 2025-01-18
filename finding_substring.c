#include <stdio.h>
#include <stdlib.h>

int stringLength(char *string){
    int i=0;
    int length=0;
    while(string[i]!='\n'&& string[i]!='\0'){
        i++;
        length++;
    }
    //printf("%d\n",length);
    return length;
}

int findSubstring(char *stringIn,char *subString){
    int stringIn_length=stringLength(stringIn);
    int subString_length=stringLength(subString);
    for(int i=0;i<stringIn_length;i++){
        if(subString[0]==stringIn[i]){
            int start=i;
            int j=0;
            while(j<subString_length && subString[j]==stringIn[i+j]){
                j++;
                }
            if(j==subString_length){
                return start;
                break;
            }
            }
        }
    return -1;
}
int main(){
    char inputString[100];
    printf("Main String:");
    fgets(inputString,100,stdin);
    char searchString[50];
    printf("Searching string:");
    scanf("%s",searchString);
    int resultIndex=findSubstring(inputString,searchString);
    printf("Index:%d",resultIndex);

}