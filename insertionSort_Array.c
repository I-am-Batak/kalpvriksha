#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertionSort(int *arr,int len){
    for(int i=1;i<len;i++){
        int j=i;
        int swapindex=i;
        while(j>0){
            if(arr[j-1]>arr[j]){
                swap(&arr[j-1],&arr[j]);
            }
            j--;
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
    insertionSort(arr,len);
    printf("Sorted Array:");
    printArray(arr,len);
    return 0;
}