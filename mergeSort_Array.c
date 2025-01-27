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

void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int *l_arr=(int *)malloc(size1*sizeof(int));
    int *r_arr=(int *)malloc(size2*sizeof(int));
    for (int i = 0; i < size1; i++) {
        l_arr[i] = arr[left + i];
    }
    for (int j = 0; j < size2; j++) {
        r_arr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, index = left;
    while (i < size1 && j < size2) {
        if (l_arr[i] <= r_arr[j]) {
            arr[index] = l_arr[i];
            i++;
        } else {
            arr[index] = r_arr[j];
            j++;
        }
        index++;
    }
    while (i < size1) {
        arr[index] = l_arr[i];
        i++;
        index++;
    }
    while (j < size2) {
        arr[index] = r_arr[j];
        j++;
        index++;
    }
    free(l_arr);
    free(r_arr);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr,0,len-1);
    printf("Sorted Array:");
    printArray(arr,len);
    return 0;
}