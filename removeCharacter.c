#include <stdio.h>
#include <stdlib.h>

void removeCharacter(char string[],char character,char stringOut[]){
    int i=0;
    int index=0;
    while(string[i]!='\0' && string[i]!='\n'){
        if(string[i]!=character){
            stringOut[index++]=string[i];
        }
        i++;
    }
    stringOut[index]='\0';
}

int main(){
    char inputString[100];
    char outString[100];
    fgets(inputString,100,stdin);
    char toRemove;
    scanf("%c",&toRemove);
    removeCharacter(inputString,toRemove,outString);
    printf("%s",outString);

}
