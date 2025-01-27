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

char *my_strcat(char *dest, char src) {
    int length = strLen(dest);
    dest[length] = src;
    dest[length + 1] = '\0';
    return dest;
}

char *getInputString(char *prompt){
    char *input = (char *)malloc(1001 * sizeof(char));
    input[0] = '\0';
    printf("%s", prompt);
    scanf("%1000[^\n]", input);
    getchar();
    return input;
}

char *removedOccurence(char *input, char removeChar){
    char *newStr = (char *)malloc(1001 * sizeof(char));
    newStr[0] = '\0';
    int length = strLen(input);
    for(int ind = 0; input[ind] != '\0'; ind++){
        if(input[ind] != removeChar){
            char temp = input[ind];
            my_strcat(newStr, temp);
        }
    }
    return newStr;
}

int main(){
    char *input = getInputString("Enter input string : ");
    char removedChar;
    printf("Enter character that has to be removed - ");
    scanf(" %c", &removedChar);

    char *removedCharString = removedOccurence(input, removedChar);
    printf("%s\n", removedCharString);
    free(input);
    free(removedCharString);
    return 0;
}