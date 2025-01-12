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

char* getInputString(char *prompt) {
    char *str = (char *)malloc(1001 * sizeof(char));
    *str = '\0';
    printf("%s", prompt);
    scanf("%1000[^\n]", str);
    getchar();
    return str;
}

char * getLongestWord(char *input, int inputLength){
    int maxi = 0;
    int currentLength = 0;
    char *longestWord = NULL;
    char *currentWord = input;

    while(*input != '\0'){
        if(*input == ' ' || *(input+1) == '\0'){
            if (*input == ' '){
                *input = '\0';
            }

            currentLength = input - currentWord;
            if(currentLength > maxi){
                maxi = currentLength;
                longestWord = currentWord;
            }

            currentWord = input + 1;
        }
        input++;
    }
    return longestWord;
}

int main(){
    char *input = getInputString("Enter a string : ");
    int inputLength = strLen(input);
    char *str = getLongestWord(input, inputLength);
    printf("%s\n", str);
    free(input);
    return 0;
}