#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void findRepeat(int B, int M, int repeat[], int *length){
    int flagBool[100] = {0};  //array for not repeating for same mod results
    int value = 1;  //initial modulus answer for N = 0

    while(!flagBool[value]){
        flagBool[value] = 1;
        repeat[(*length)++] = value;
        value = (value * B) % M;  
    }
}

int main(){
    int B, N, M;
    printf("Enter Base (B): ");
    scanf("%d", &B);
    printf("Enter Exponent (N): ");
    scanf("%d", &N);
    printf("Enter Modulus (M): ");
    scanf("%d", &M);
    if (B <= 0 || N < 0 || M <= 1) { //Inout Validation
        printf("Invalid input!\n");
        return 1;
    }

    int repeat[100], length = 0;
    findRepeat(B, M, repeat, &length);//find the repeating modulus results and store

    int reduceExponent = N % length;
    int result = repeat[reduceExponent];
    printf("%d", result);
    return 0;
}