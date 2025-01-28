#include<stdio.h>
#include<stdlib.h>

int *inputArray(int size){
    int *array = (int *)malloc(size * sizeof(int));

    for(int index = 0; index < size; index++){
        scanf("%d", (array + index));
    }
    return array;
}

void display(int *array, int size){
    for(int index = 0; index < size; index++){
        printf("%d ", array[index]);
    }
    printf("\n");
}

void merge(int *arr, int low, int mid, int high){
    int n1 = mid-low+1, n2 = high - mid;
    int tempA[n1], tempB[n2];

    for(int i = 0; i < n1; i++){
        tempA[i] = arr[low+i];
    }
    for(int i = 0; i < n2; i++){
        tempB[i] = arr[mid+i+1];
    }
    int tempAIndex = 0, tempBIndex = 0, index = low;

    while(tempAIndex < n1 && tempBIndex < n2){
        if(tempA[tempAIndex] > tempB[tempBIndex]){
            arr[index++] = tempB[tempBIndex++];
        }else{
            arr[index++] = tempA[tempAIndex++];
        }
    }
    while(tempAIndex < n1){
        arr[index++] = tempA[tempAIndex++];
    }
    while(tempBIndex < n2){
        arr[index++] = tempB[tempBIndex++];
    }
}

void mergeSort(int *unsortedArray, int low, int high){
    if(low < high){
        int mid = low + (high - low)/2;

        mergeSort(unsortedArray, low, mid);
        mergeSort(unsortedArray, mid+1, high);
        merge(unsortedArray, low, mid, high);
    }
}

int main(){
    int array_size;
    scanf("%d", &array_size);
    int *unsortedArray = inputArray(array_size);
    mergeSort(unsortedArray, 0, array_size-1);
    printf("Sorted Array - ");
    display(unsortedArray, array_size);
    free(unsortedArray);
    return 0;
}