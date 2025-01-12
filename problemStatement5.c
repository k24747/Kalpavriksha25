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

int isNum(char c){
    return (c >= '0' && c <= '9');
}

int isChar(char c){
    return (c >= 'a' && c <= 'z') || (c <= 'Z' && c >= 'A');
}

char* getInputString(char *prompt) {
    char *str = (char *)malloc(1001 * sizeof(char));
    *str = '\0';
    printf("%s", prompt);
    scanf("%1000[^\n]", str);
    getchar();
    return str;
}

int charToInteger(char *input, int length){
    int num = 0, isNegative = 0;
    if (input[0] == '-'){
        isNegative = 1;
        input++; 
    }
    for(int ind = 0; input[ind] != '\0'; ind++){
        if (!isNum(input[ind])){
            return 0; 
        }
        num = num * 10 + (input[ind] - '0');
    }
    if(isNegative){
        num = -num;
    }
    return num;
}

int main(){
    char *input = getInputString("Enter the input string to convert to integer : ");
    int length = strLen(input);
    int number = charToInteger(input, length);
    printf("%d\n", number);
    free(input);
    return 0;
}