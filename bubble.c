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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int *bubbleSort(int *array, int size){
    int swapped = 0;
    int *sortedArray = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        sortedArray[i] = array[i];
    }
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(sortedArray[j] > sortedArray[j+1]){
                swap(&sortedArray[j], &sortedArray[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
    }
    return sortedArray;
}

int main(){
    int array_size;
    scanf("%d", &array_size);
    int *unsortedArray = inputArray(array_size);
    int *sortedArray = bubbleSort(unsortedArray, array_size);
    printf("Sorted Array - ");
    display(sortedArray, array_size);
    printf("Unsorted Array - ");
    display(unsortedArray, array_size);

    free(unsortedArray);
    free(sortedArray);
    return 0;
}