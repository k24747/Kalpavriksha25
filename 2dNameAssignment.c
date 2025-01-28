#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isVowel(char *str){
    char ch = str[0];
    if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || 
    ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){
        return 1;
    }
    return 0;
}

int len(char *str){
    int count = 0;
    while(*str != '\0'){
        count++;
        str++;
    }
    return count;
}

int main(){
    int numRow, numCol;
    printf("Enter number of rows: ");
    scanf("%d", &numRow);
    if(numRow < 1 || numRow > 10){
        printf("Invalid number of rows\n");
        exit(1);
    }
    printf("Enter number of columns: ");
    scanf("%d", &numCol);
    if(numCol < 1 || numCol > 101){
        printf("Invalid number of columns\n");
        exit(1);
    }

    char ***names = (char ***)malloc(numRow * sizeof(char **));
    for (int row = 0; row < numRow; row++){
        names[row] = (char **)malloc(numCol * sizeof(char *));
        for (int col = 0; col < numCol; col++){
            names[row][col] = (char *)malloc(51 * sizeof(char));
        }
    }

    printf("\nEnter the names:\n");
    for (int row = 0; row < numRow; row++){
        for(int col = 0; col < numCol; col++){
            printf("Names at (%d,%d): ", row, col);
            scanf("%50s", names[row][col]);
        }
    }

    printf("\nThe 2d Array of names is\n");
    for (int row = 0; row < numRow; row++){
        for(int col = 0; col < numCol; col++){
            printf("%s ", names[row][col]);
        }
        printf("\n");
    }
    int count = 0;
    for (int row = 0; row < numRow; row++){
        for(int col = 0; col < numCol; col++){
            if (isVowel(names[row][col])){
                count++;
            }
        }
    }

    printf("\nNumber of names starting with a vowel: %d\n", count);

    int longestNameRow  = 0, longestNameCol  = 0, max = -1;
    for (int row = 0; row < numRow; row++){
        for(int col = 0; col < numCol; col++){
            int length = len(names[row][col]);
            if (length > max){
                max = length;
                longestNameRow = row;
                longestNameCol = col;
            }
        }
    }

    printf("The longest name: %s", names[longestNameRow][longestNameCol]);

    for (int row = 0; row < numRow; row++) {
        for (int col = 0; col < numCol; col++) {
            free(names[row][col]); 
        }
        free(names[row]);
    }
    free(names);
    return 0;
}