#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}

void linearSearch(int *arr,int len,int num){
    for(int i=0;i<len;i++){
        if(arr[i]==num){
            printf("Found at %d position in Array",i+1);
            return;
        }
    }
    printf("Given Element doesn't exist in array");
}

int makeArray(int **arr){
    int n;
    printf("Enter Number of Elements:");
    scanf("%d",&n);
    *arr=(int *)realloc(*arr,n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter %d element:",i+1);
        scanf("%d",&(*arr)[i]);
    }
    return n;
}
int main(){
    int *arr=(int *)malloc(sizeof(int));
    int len=makeArray(&arr);
    printf("Generated Array:");
    printArray(arr,len);
    printf("\n");
    int num;
    printf("Enter the element for searching:");
    scanf("%d",&num);
    linearSearch(arr,len,num);
    return 0;
}