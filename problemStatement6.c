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

int isAnagarmStringOrNot(char *input, int length, char *anagarm, int anagarmLength){
    int count = 0;
    for(int ind = 0; ind < length; ind++){
        for(int i = 0; i < anagarmLength; i++){
            if(input[ind] == anagarm[i]){
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
    char *anagarm = getInputString("Enter a anagarm string: ");

    int inputLength = strLen(inputString);
    int anagarmLength = strLen(anagarm);

    int flag = 0;
    if(inputLength != anagarmLength){
        flag = 0;
    }else{
        flag = isAnagarmStringOrNot(inputString, inputLength, anagarm, anagarmLength);
    }

    if(flag) printf("True\n");
    else printf("False\n");

    free(inputString);
    free(anagarm);
    return 0;
}