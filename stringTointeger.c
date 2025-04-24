#include <stdio.h>
#include <stdlib.h>

int stringLength(char *string){
    int length=0;
    int i=0;
    while(string[i]!='\0' && string[i]!='\n'){
        length++;
        i++;
    }
    return length;
}

int toInteger(char *string){
    int length=stringLength(string);
    int sign=1;
    int nums=0;
    for(int i=0;i<length;i++){
        if(string[i]=='-'){
            sign=-1;
        }
        else if(string[i]>='0' && string[i]<='9'){
            nums=nums * 10+(string[i]-'0');
        }
        else{
            return nums;
        }

    }
    nums=sign*nums;
    return nums;
}

int main(){
    char inputString[100];
    fgets(inputString,100,stdin);
    int result=toInteger(inputString);
    printf("Result:%d",result);
}