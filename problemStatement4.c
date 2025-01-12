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

int isRotatedStringOrNot(char *input, int length, char *rotateStr, int rotateLength){
    int count = 0;
    for(int ind = 0; ind < length; ind++){
        for(int i = 0; i < rotateLength; i++){
            if(input[ind] == rotateStr[i]){
                count++;
                break;
            }
        }
    }
    if(count == length) return 1;
    return 0;
}

int main(){
    char *inputString = getInputString("Enter a string: ");
    char *rotateString = getInputString("Enter a rotate string: ");

    int inputLength = strLen(inputString);
    int rotateLength = strLen(rotateString);

    int flag = 0;
    if(inputLength != rotateLength){
        flag = 0;
    }else{
        flag = isRotatedStringOrNot(inputString, inputLength, rotateString, rotateLength);
    }

    if(flag) printf("True\n");
    else printf("False\n");

    free(inputString);
    free(rotateString);
    return 0;
}