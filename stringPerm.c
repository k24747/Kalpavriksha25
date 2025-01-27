#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int strLen(char *input){
    int charCount = 0;
    while(*input != '\0'){
        charCount++;
        input++;
    }
    return charCount;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *getInputString(char *prompt){
    char *input = (char *)malloc(1001 * sizeof(char));
    input[0] = '\0';
    printf("%s", prompt);
    scanf("%1000[^\n]", input);
    getchar();
    return input;
}

void allPermutations(char *input, int length, int *permCount, char *words[], int ind){
    if(ind == length){
        words[*permCount] = (char *)malloc((length+1) * sizeof(char));
        strcpy(words[*permCount], input);
        (*permCount)++;
        return;
    }
    for(int i = ind; i < length; i++){
        swap(&input[i], &input[ind]);
        allPermutations(input, length, permCount, words, ind+1);
        swap(&input[i], &input[ind]);
    }
}

void printPermutations(char *words[], int permCount) {
    for (int i = 0; i < permCount; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
}

int main(){
    char *input = getInputString("Enter input string : ");
    char *words[100];
    int length = strLen(input);
    int permCount = 0;

    allPermutations(input, length, &permCount, words, 0);
    printPermutations(words, permCount);
    free(input);
    return 0;
}