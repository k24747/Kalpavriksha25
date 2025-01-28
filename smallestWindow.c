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

char *getInputString(char *prompt)
{
    char *input = (char *)malloc(1001 * sizeof(char));
    input[0] = '\0';
    printf("%s", prompt);
    scanf("%1000[^\n]", input);
    getchar();
    return input;
}

void findMinimumWindow(char *input, char *pat, int *ind, int *size){
    int inputLen = strLen(input);
    int patLen = strLen(pat);
    int freqInput[256] = {0};
    int freqPat[256] = {0};
    for(int i = 0; i < patLen; i++){
        freqPat[pat[i]]++;
    }
    
    int start = 0, count = 0, minLen = inputLen + 1, startIndex = -1;

    for(int end = 0; end < inputLen; end++){
        freqInput[(int)input[end]]++;

        if(freqPat[(int)input[end]] != 0 && 
        freqInput[(int)input[end]] <= freqPat[(int)input[end]]){
            count++;
        }

        if(count == patLen){
            while(freqPat[(int)input[start]] == 0 || 
            freqInput[(int)input[start]] > freqPat[(int)input[start]]){
                if(freqInput[(int)input[start]] > freqPat[(int)input[start]]){
                    freqInput[(int)input[start]]--;
                }
                start++;
            }

            int windowLen = end - start + 1;
            if(windowLen < minLen){
                minLen = windowLen;
                startIndex = start;
            }
        }
    }
    *ind = startIndex;
    *size = minLen;
}

int main()
{
    char *input = getInputString("Enter string: ");
    char *pat = getInputString("Enter pattern string: ");
    int ind = 0, size = 0;

    findMinimumWindow(input, pat, &ind, &size);

    if (ind == -1){
        printf("No such window exists\n");
    }else{
        printf("Minimum window: ");
        for (int i = ind; i < ind + size; i++){
            printf("%c", input[i]);
        }
        printf("\n");
    }

    free(input);
    free(pat);
    return 0;
}