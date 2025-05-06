#include <stdlib.h>
#include <stdio.h>

int isSpace(char c){
    if(c==' '){
        return 1;
    }
    else{
        return 0;
    }
}

int countWords(char sentence[]){
    int i=0;
    int words=0;
    while(sentence[i]!='\n' && sentence[i]!='\0'){
        if(isSpace(sentence[i])==1){
                i++;
            }
        else{
            words++;
            while(sentence[i]!='\0' && isSpace(sentence[i])==0){
                i++;
            }
        }
    }
    return words;
}


int main(){
    char inputSentence[100];
    fgets(inputSentence,100,stdin);
    int words=countWords(inputSentence);
    printf("No. of Words :%d\n",words);
    return 0;
}