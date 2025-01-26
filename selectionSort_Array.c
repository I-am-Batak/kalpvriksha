#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}

void selectionSort(int *arr,int len){
    for(int i=0;i<len-1;i++){
        int swapIndex=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[swapIndex]){
                swapIndex=j;
            }
        }
        if(swapIndex!=i){
        int temp=arr[i];
        arr[i]=arr[swapIndex];
        arr[swapIndex]=temp;
        }

    }
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
    selectionSort(arr,len);
    printf("Sorted Array:");
    printArray(arr,len);
    return 0;
}