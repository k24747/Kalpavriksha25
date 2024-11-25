#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

int isNum(char c) {
    if(c>='0' && c<='9'){
        return 1;
    }
    return 0;
    }

int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/'){
        return 1;
    }
    return 0;
    }

int Operation(int operand1 ,int operand2, char operator){
    int ans  = 0;
switch(operator){
    case '+':
    ans = operand1 + operand2;
    break;

    case '-':
    ans = operand1 - operand2;
    break;

    case '*':
    ans = operand1 * operand2;
    break;

    case '/':
    if(operand2 == 0)
    {
        printf("Error: Division by zero.\n");
        exit(0);
    }
    ans = operand1 / operand2;
    break;
    }

    return ans;
}

int precedence(char c){
    return c=='+' || c=='-' ? 1 : 2;
    }

int Calculate(char expression[], int n){
    int valueTop = -1, operatorTop = -1, flag = 1, i = 0;
    int values[MAX], operators[MAX];

    while(expression[i] != '\0'){
        while(expression[i] == ' '){
            i++;
            continue;
        }// Remove the whitespaces present in expression

        if(isNum(expression[i])){
            int num = 0;
            while(i < n && isNum(expression[i])){ //converts multiple number char to int
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            valueTop++;
            values[valueTop] = num;
            flag = 0;
        }
        else if(isOperator(expression[i])){
            if(flag == 1){
                printf("Error: Invalid expression.\n");
                exit(0);
            }
            while(operatorTop != -1 && precedence(expression[i]) <= precedence(operators[operatorTop])){
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = operators[operatorTop--];
                int operationAns = Operation(a, b, op);
                values[++valueTop] = operationAns;
            }
            operators[++operatorTop] = expression[i];
            i++;
            flag = 1;
        }
        else{
            printf("Error: Invalid expression.\n");
            exit(0);
        }
    }
    if(flag == 1){
        printf("Error: Invalid expression.\n");
        exit(0);
    }

    while(operatorTop != -1){
        int b = values[valueTop--];
        int a = values[valueTop--];
        char op = operators[operatorTop--];
        int operationAns = Operation(a, b, op);
        values[++valueTop] = operationAns;
    }
    return values[valueTop];
}

int main(){
    char expression[MAX];
    int i = 0, ch;

    while((ch = getchar()) != '\n' && ch != EOF && i < 99){
        expression[i++] = ch;
    }
    expression[i] = '\0';
    int n = strlen(expression);
    int ans = Calculate(expression, n);
    printf("%d", ans);
    return 0;
}