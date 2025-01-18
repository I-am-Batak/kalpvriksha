#include <stdio.h>
#include <stdlib.h>

int stringLength(char string[]){
    int i=0;
    int length=0;
    while(string[i]!='\n'&& string[i]!='\0'){
        i++;
        length++;
    }
    //printf("%d\n",length);
    return length;
}

void sort(char string[],int string_len){
    for(int i=0;i<string_len;i++){
        for(int j=0;j<string_len;j++){
            if(string[j]>string[j+1]){
                char temp=string[j];
                string[j]=string[j+1];
                string[j+1]=temp;
            }
        }
    }
}

int isAnagram(char string1[],char string2[]){
    int string1_len=stringLength(string1);
    int string2_len=stringLength(string2);
    if(string1_len!=string2_len){
        return 0;
    }
    sort(string1,string1_len);
    sort(string2,string2_len);
    for(int i=0;i<string1_len;i++){
        if(string1[i]!=string2[i]){
            return 0;
        }
    }
    return 1;

}

int main(){
    char string1[100];
    char string2[100];
    fgets(string1,100,stdin);
    fgets(string2,100,stdin);
    int result=isAnagram(string1,string2);
    if(result==0){
        printf("False");
    }
    else{
        printf("True");
    }
}