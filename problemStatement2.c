#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strLen(char *c){
    int count = 0;
    while(*c != '\0'){
        count++;
        c++;
    }
    return count;
}

void countWords(char *input, int length){
    char *totalWords[length/2 + 1];
    int wordCount = 0;
    while(*input == ' '){
        input++;
    }
    while(*input != '\0'){
        while(*input == ' '){
            input++;
        }
        if(*input == '\0'){
            break;
        }
        totalWords[wordCount++] = input;
        while(*input && *input != ' '){
            input++;
        }
        if(*input){
            *input = '\0';
            input++;
        }
    }
    printf("%d\n", wordCount);
}

int main() {
    char *inputString = (char *)malloc(1001 * sizeof(char));
    *inputString = '\0';

    printf("Enter a string: ");
    scanf("%1000[^\n]", inputString);
    getchar();

    int inputLength = strLen(inputString);
    countWords(inputString, inputLength);

    free(inputString);
    return 0;
}