#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selectPivot(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = selectPivot(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
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
    quicksort(arr,0,len-1);
    printf("Sorted Array:");
    printArray(arr,len);
    return 0;
}