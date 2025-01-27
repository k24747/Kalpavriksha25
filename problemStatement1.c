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

void removeDuplicateCharacters(char *input, int length) {
    char *uniqueCharacters = (char *)malloc(length * sizeof(char));
    int uniqueIndex = 0;

    for (int i = 0; i < length; i++) {
        int isDuplicate = 0;

        for (int j = 0; j < uniqueIndex; j++) {
            if (input[i] == uniqueCharacters[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            uniqueCharacters[uniqueIndex++] = input[i];
        }
    }

    uniqueCharacters[uniqueIndex] = '\0'; 
    printf("%s", uniqueCharacters);

    free(uniqueCharacters); 
}

int main() {
    char *inputString = (char *)malloc(1001 * sizeof(char));
    *inputString = '\0';

    printf("Enter a string: ");
    scanf("%1000[^\n]", inputString);
    getchar();

    int inputLength = strlen(inputString);
    removeDuplicateCharacters(inputString, inputLength);

    free(inputString);
    return 0;
}
