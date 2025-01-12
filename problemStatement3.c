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

int indexOfSubString(char *input, int length, char *subString, int subLength){
    int index = 0;
    for(int ind = 0; input[ind] != '\0'; ind++){
        if(input[ind] == subString[0]){
            index = ind;
            int i = 0;
            while(subString[i] != '\0' && subString[i] == input[ind+i]  && input[ind + i] != '\0'){
                i++;
            }
            if(i == subLength){
                return index;
            }
        }
    }
    return -1;
}

int main(){
    char *inputString = (char *)malloc(1001 * sizeof(char));
    *inputString = '\0';

    printf("Enter a string: ");
    scanf("%1000[^\n]", inputString);
    getchar();

    int inputLength = strLen(inputString);

    char *subString = (char *)malloc(1001 * sizeof(char));
    *subString = '\0';

    printf("Enter a sub string: ");
    scanf("%1000[^\n]", subString);
    getchar();

    int subLength = strLen(subString);

    int index = indexOfSubString(inputString, inputLength, subString, subLength);
    printf("%d\n", index);

    free(inputString);
    free(subString);
    return 0;
}