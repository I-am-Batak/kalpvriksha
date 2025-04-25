#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void concatenate(char *string1,char string2[],char *stringOut){
    //int string1_len=stringLength(string1);
    int k=0;
    int i=0;
    while(string1[i]!='\n' && string1[i]!='\0'){
        stringOut[k++]=string1[i];
        i++;
    }
    //int string2_len=stringLength(string2);
    i=0;
    while(string2[i]!='\n' && string2[i]!='\0'){

        stringOut[k++]=string2[i];
        i++;
    }
    stringOut[k]='\0';
    // for(int i=0;i<=k;i++){
    //     printf("%c",stringOut[i]);
    // }
}

int main(){
    char string1[100];
    char string2[100];
    char string3[200];
    fgets(string1,100,stdin);
    fgets(string2,100,stdin);
    
    concatenate(string1,string1,string3);
    int result=findSubstring(string3,string2);
    if(result>0){
        printf("True");
    }
    else{
        printf("False");
    }
}

