#include <stdio.h>

int stringLength(char string[]){
    int i=0;
    int length=0;
    while(string[i]!='\n'&& string[i]!='\0'){
        i++;
        length++;
    }
    return length;
}

int removeDuplicates(char string[],int length){
    int index=0;
    while(string[index]!='\n' && string[index]!='\0'){
        if(string[index]==' '){
            index++;
        }
        else if(string[index]==string[index+1]){
                for(int j=index+2;j<length;j++){
                    string[index]=string[j];
                    index++;
                }
                string[length-2]='\0';
                removeDuplicates(string,length-2);
            }
        else{
            index++;
        }
    }
        return 1;
}


int main()
{
    char string[100];
    fgets(string,100,stdin);
    int length=stringLength(string);
    int result=removeDuplicates(string,length);
    printf("%s",string);
    return 0;
}