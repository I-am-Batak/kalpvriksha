#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}

void binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Element found at %d position in array",mid+1);
            return;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    printf("Element doesn't exist in the array");
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
    binarySearch(arr,len,num);
    return 0;
}