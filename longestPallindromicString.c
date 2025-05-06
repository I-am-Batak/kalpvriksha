#include <stdio.h>
#include <string.h>
int main()
{
	
	char string[100];
	//fgets(string,100,stdin);
	scanf("%[^\n]",string);
	int len=strlen(string);
	printf("1. Length:%d\n",len);
	int maxLen=0;
	char maxPallindrome[100];
	for(int i=0;i<len;i++){
	    int l=i,r=i;
	    printf("2. l:%d r:%d i:%d\n",l,r,i);
	    if(string[l]==string[r+1]){
	            printf("3. string[%d]:%c==string[%d]:%c\n",l,string[l],r+1,string[r+1]);
	            r=i+1;
	    }
	    while(l-1>=0 && r+1<len && string[l-1]==string[r+1]){
	         printf("4. string[%d]:%c==string[%d]:%c\n",l,string[l],r,string[r]);
	        l--;
	        r++;
	    }
	    if(r-l+1>maxLen){
	        printf("5. %d>%d\n",r-l+1,maxLen);
	        maxLen=r-l+1;
	        printf("6. maxlen:%d\n",maxLen);
	        int index=0;
	        for(int j=l;j<=r;j++){
	            maxPallindrome[index++]=string[j];
	        }
	        maxPallindrome[index]='\0';
	    }
	        
	   
	}
	printf("%s",maxPallindrome);
	return 0;
}