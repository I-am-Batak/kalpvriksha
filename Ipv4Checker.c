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

int isInteger(char c){
    return (c>='0' && c<='9');
}

int validate(char string[]){
    int stringLen=stringLength(string);
    int start;
    int end;
    int cont_dot=0;
    int dotCount=0;
    int octet=0;
    for(int i=0;i<stringLen;i++){
        int index=0;
        start=i;
        end=i;
        if(string[i]=='.'){
            cont_dot++;
            dotCount++;
            if(cont_dot==2){
                return 0;
            }
            continue;
        }
        cont_dot=0;
        while(string[end]!='.'&& end<stringLen){
            end++;
        }
        if(string[start]=='0' && end-start>1){
            return 0;
        }
        else{
        char tempNum[4];
        for(int j=start;j<end;j++){
            tempNum[index++]=string[j];
        }
        octet++;
        tempNum[index]='\0';
        
        int num=toInteger(tempNum);
        if(num>255 || num<0){
            return 0;
        }
        }
        
        i=end-1;
    }
    if(dotCount!=3 || octet!=4){
        return 0;
    }
    return 1;
}



int main(){
    char string[15];
    int ipAddress[4];
    fgets(string,15,stdin);
    for(int i=0;string[i]!='\n'&&string[i]!='\0';i++){
        if(isInteger(string[i])|| string[i]=='.'){
            continue;
        }
        else{
            printf("Invalid");
            return 0;
    }
    }
    printf("%s\n",string);
    int result=validate(string);
    if(result==1){
        printf("Valid");
    }
    else{
        printf("Invalid");
    }
    
}