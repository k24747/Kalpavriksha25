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

void longestPalindromicSubstring(char *input, int length, int *size, int *index){
    for(int i = 0; i < length-1; i++){
        for(int j = i+1; j < length; j++){
            if(input[i] == input[j]){
                int low = i+1;
                int high = j-1;
                while(low <= high){
                    if(input[low] == input[high]){
                        low++, high--;
                    }else{
                        break;
                    }
                }
                if(*size < (j-i+1)) {
                    *size = j-i+1;
                    *index = i;
                }
            }
        }
    }
}

int main(){
    char *input = getInputString("Enter input string : ");
    int length = strLen(input);
    int size = 0;
    int index = 0;
    longestPalindromicSubstring(input, length, &size, &index);

    if(size > 0 && length != 1){
        printf("Longest Palindromic Substring: ");
        for (int i = index; i < index + size; i++) {
            printf("%c", input[i]);
        }
        printf("\n");
    }else if(length == 1){
        printf("%s\n", input);
    }
    else{
        printf("No palindrome found.\n");
    }

    free(input);
    return 0;
}