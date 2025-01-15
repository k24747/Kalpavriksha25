#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getInputString(char *prompt) {
    char *input = (char *)malloc(1001 * sizeof(char));
    input[0] = '\0';
    printf("%s", prompt);
    scanf("%1000[^\n]", input);
    getchar();
    return input;
}

int expandAroundCenter(char *input, int left, int right, int *start) {
    int len = strlen(input);
    while (left >= 0 && right < len && input[left] == input[right]) {
        left--;
        right++;
    }
    *start = left + 1; 
    return right - left - 1;
}

void longestPalindromicSubstring(char *input, int *size, int *index) {
    int length = strlen(input);
    if (length == 0) {
        *size = 0;
        *index = -1;
        return;
    }
    
    int maxLen = 0;
    int start = 0;
    for (int i = 0; i < length; i++) {
        int len1 = expandAroundCenter(input, i, i, &start);
        int len2 = expandAroundCenter(input, i, i + 1, &start);
        int curMax = (len1 > len2) ? len1 : len2;
        if (curMax > maxLen) {
            maxLen = curMax;
            *index = start; 
        }
    }
    *size = maxLen;
}

int main() {
    char *input = getInputString("Enter input string: ");
    int size = 0, index = 0;

    longestPalindromicSubstring(input, &size, &index);

    if (size > 0) {
        printf("Longest Palindromic Substring: ");
        for (int i = index; i < index + size; i++) {
            printf("%c", input[i]);
        }
        printf("\n");
    } else {
        printf("No palindrome found.\n");
    }
    free(input); 
    return 0;
}
