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

int *insertionSort(int *array, int size){
    int *sortedArray = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        sortedArray[i] = array[i];
    }
    for (int i = 1; i < size; ++i){
        int key = sortedArray[i];
        int j = i - 1;
        while(j >= 0 && sortedArray[j] > key){
            sortedArray[j + 1] = sortedArray[j];
            j = j - 1;
        }
        sortedArray[j + 1] = key;
    }
    return sortedArray;
}

int main(){
    int array_size;
    scanf("%d", &array_size);
    int *unsortedArray = inputArray(array_size);
    int *sortedArray = insertionSort(unsortedArray, array_size);
    printf("Sorted Array - ");
    display(sortedArray, array_size);
    printf("Unsorted Array - ");
    display(unsortedArray, array_size);

    free(unsortedArray);
    free(sortedArray);
    return 0;
}