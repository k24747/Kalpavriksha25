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

char *getInputString(char *prompt){
    char *input = (char *)malloc(1001 * sizeof(char));
    input[0] = '\0';
    printf("%s", prompt);
    scanf("%1000[^\n]", input);
    getchar();
    return input;
}

char *strCat(char *dest, char *src){
    while(*dest != '\0'){
        dest++;
    }
    while(*src != '\0'){
        *dest = *src;
        src++, dest++;
    }
    *dest = '\0';
    return dest;
}

void validRotationString(char *input, char *rotateString){
    int length = strLen(input);
    int rotateLength = strLen(rotateString);

    if(length != rotateLength){
        printf("False\n");
        return;
    }

    char *doubleStr = (char *)malloc(((2 * length) + 1) * sizeof(char));
    *doubleStr = '\0';
    strCat(doubleStr, input);
    strCat(doubleStr, rotateString);

    int doubleLength = strLen(doubleStr);
    int flag = 0;
    for(int ind = 0; ind <= doubleLength-rotateLength; ind++){
        int i = 0;
        while(i < rotateLength && doubleStr[ind+i] == rotateString[i]){
            i++;
        }
        if(i == rotateLength){
            flag = 1;
            break;
        }
    }
    if(flag) printf("True\n");
    else printf("False\n");
}

int main(){
    char *input = getInputString("Enter input string : ");
    char *rotateString = getInputString("Enter rotated string : ");

    validRotationString(input, rotateString);
    return 0;
}