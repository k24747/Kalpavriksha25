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

int strCmp(char *a, char *b){
    int flag = 0;
    while(*a != '\0' && *b != '\0'){
        if(*a != *b) flag = 1;
        a++, b++;
    }
    return flag;
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

char *removeAdjacentDuplicates(char *input, int length){
    char *str = (char *)malloc(length+1 * sizeof(char));
    *str = '\0';
    while(*input != '\0'){
        if(*(input + 1) != '\0' && *input == *(input+1)){
            input += 2;
            continue;
        }
        char temp = *input;
        my_strcat(str, temp);
        input++;
    }  
    return str;
}

int main(){
    char *input = getInputString("Enter the string : ");
    int length = strLen(input);
    char *result = NULL;
    while(1){
        result = removeAdjacentDuplicates(input, length);
        if(strCmp(input, result) == 0){
            printf("%s\n", result);
            free(input);
            free(result);
            break;
        }
        free(input); 
        input = result; 
        length = strLen(input); 
    }
    return 0;
}