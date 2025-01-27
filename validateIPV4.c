#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strLen(char *input)
{
    int charCount = 0;
    while (*input != '\0')
    {
        charCount++;
        input++;
    }
    return charCount;
}

int isNum(char c)
{
    return (c >= '0' && c <= '9');
}

char *getInputString(char *prompt)
{
    char *input = (char *)malloc(16 * sizeof(char));
    input[0] = '\0';
    printf("%s", prompt);
    scanf("%15[^\n]", input);
    getchar();
    return input;
}

void validateIPV4(char *input)
{
    int flag = 1;
    int num = 0;
    int dotCount = 0;
    char *currentStart = input;
    char prevChar = '\0';

    while(*input != '\0' && flag){
        if(isNum(*input)){
            num = num * 10 + (*input - '0');
            if(num > 0 && *currentStart == '0'){
                flag = 0;
            }
            if(*currentStart == '0' && *(currentStart+1) == '0'){
                flag = 0;
            }
            if(num > 255){
                flag = 0;
            }
        }
        else if(*input == '.'){
            dotCount++;
            if(prevChar == '.' || prevChar == '\0') flag = 0;
            if(num < 0 || num > 255){
                flag = 0;
            }
            num = 0;
            currentStart = input + 1;

        }else{
            flag = 0;
        }
        prevChar = *input;
        input++;
    }

    if(dotCount != 3 && num < 0 && num > 255 && prevChar == '.'){
        flag = 0;
    }

    if (flag){
        printf("Valid\n");
    }
    else{
        printf("Invalid\n");
    }
}

int main()
{
    char *inputIPV4 = getInputString("Enter IPV4 address to validate : ");
    validateIPV4(inputIPV4);
    free(inputIPV4);
    return 0;
}