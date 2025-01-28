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

int *selectionSort(int *array, int size){
    int *sortedArray = (int *)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        sortedArray[i] = array[i];
    }
    for (int i = 0; i < size - 1; i++){
    int mini = i;
    for (int j = i + 1; j < size; j++) {
      if (sortedArray[j] < sortedArray[mini]) {
        mini = j;
      }
    }
    int temp = sortedArray[mini];
    sortedArray[mini] = sortedArray[i];
    sortedArray[i] = temp;
    }
    return sortedArray;
}

int main(){
    int array_size;
    scanf("%d", &array_size);
    int *unsortedArray = inputArray(array_size);
    int *sortedArray = selectionSort(unsortedArray, array_size);
    printf("Sorted Array - ");
    display(sortedArray, array_size);
    printf("Unsorted Array - ");
    display(unsortedArray, array_size);

    free(unsortedArray);
    free(sortedArray);
    return 0;
}