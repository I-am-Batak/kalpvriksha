#include <stdlib.h>
#include <stdio.h>

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

void longestWord(char *inputString,char word[]){
    int length=stringLength(inputString);
    int longestLength=0;
    // for(int i=0;i<length;i++){
    int i=0;
        while(inputString[i]!='\n' && inputString[i]!='\0' && i<length){
            if(inputString[i]==' '){
                i++;
                //printf("1. Space :%d",i);
            } 
            int start=i;
            while(inputString[i]!=' ' && inputString[i]!='\0' && inputString[i]!='\n'){
                i++;
            }
            int end=i;
            //printf("2. Start:%d, end:%d",start,end);
            int curr_len=(end-start)+1;
            if(curr_len>longestLength){
                longestLength=curr_len;
                int idx=0;
                for(int j=start;j<=end;j++){
                    word[idx++]=inputString[j];
                }
                word[idx]='\0';
            }
            i=end+1;

        
        }
    }

int main(){
    char inputSentence[100];
    fgets(inputSentence,100,stdin);
    char word[100];
    longestWord(inputSentence,word);
    printf("%s",word);
}