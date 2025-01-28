#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

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

void linearSearch(int *arr, int target, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            printf("Target value found.\n");
            return;
        }
    }
    printf("Target value not found.\n");
}

void binarySearch(int *arr, int target, int low, int high){
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == target){
            printf("Target value found.\n");
            return;
        }else if(arr[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    printf("Target value not found.\n");
}

void twoPointerSearch(int *arr, int target, int low, int high){
    while(low <= high){
        int sum = arr[low] + arr[high];
        if(sum == target){
            printf("Target sum found.\n");
            return;
        }else if(sum > target){
            high--;
        }else{
            low++;
        }
    }
    printf("Target sum not found.\n");
}

int main(){
    int array_size;
    scanf("%d", &array_size);
    int *array = inputArray(array_size);
    int choice;
    do{
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Two Pointer Search\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        int target;
        printf("Enter value to be searched ");

        switch(choice){
            case 1:
            scanf("%d", &target);
            linearSearch(array, target, array_size);
            break;
            case 2:
            scanf("%d", &target);
            int *searchingArray = bubbleSort(array, array_size);
            binarySearch(searchingArray, target, 0, array_size-1);
            break;
            case 3:
            scanf("%d", &target);
            int *searchingArray2 = bubbleSort(array, array_size);
            twoPointerSearch(searchingArray2, target, 0, array_size-1);
            break;
            case 4:
            printf("Exit\n");
            break;
            default:
            printf("Invalid Choice");
            break;
        }
    }while(choice != 4);

    free(array);
    return 0;
}