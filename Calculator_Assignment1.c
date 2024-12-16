#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isNum(char c) {
    return c >= '0' && c <= '9';
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Operation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                printf("Error: Division by zero.\n");
                exit(0);
            }
            return operand1 / operand2;
    }
    return 0;
}

int precedence(char c) {
    return c == '+' || c == '-' ? 1 : 2;
}

int Calculate(char *expression, int n) {
    int *values = (int*)malloc(n * sizeof(int));
    char *operators = (char*)malloc(n * sizeof(char));
    int valueTop = -1, operatorTop = -1, flag = 1, i = 0;

    while(expression[i] != '\0') {
        while(expression[i] == ' ') i++; 

        if (isNum(expression[i])) {
            int num = 0;
            while(i < n && isNum(expression[i])) {
                num = num * 10 + (expression[i++] - '0');
            }
            values[++valueTop] = num;
            flag = 0;
        } else if (isOperator(expression[i])) {
            if (flag == 1) {
                printf("Error: Invalid expression.\n");
                free(values); free(operators);
                exit(0);
            }
            while (operatorTop != -1 && precedence(expression[i]) <= precedence(operators[operatorTop])) {
                int b = values[valueTop--];
                int a = values[valueTop--];
                char op = operators[operatorTop--];
                values[++valueTop] = Operation(a, b, op);
            }
            operators[++operatorTop] = expression[i++];
            flag = 1;
        } else {
            printf("Error: Invalid expression.\n");
            free(values); free(operators);
            exit(0);
        }
    }

    if (flag == 1) {
        printf("Error: Invalid expression.\n");
        free(values); free(operators);
        exit(0);
    }

    while (operatorTop != -1) {
        int b = values[valueTop--];
        int a = values[valueTop--];
        char op = operators[operatorTop--];
        values[++valueTop] = Operation(a, b, op);
    }

    int result = values[valueTop];
    free(values); free(operators);
    return result;
}

int main() {
    char *expression = NULL;
    int size = 0, ch, pos = 0;

    while((ch = getchar()) != '\n') {
        expression = realloc(expression, (pos + 1) * sizeof(char));
        expression[pos++] = ch;
    }
    expression = realloc(expression, (pos + 1) * sizeof(char));
    expression[pos] = '\0';

    int n = strlen(expression);
    int ans = Calculate(expression, n);
    printf("%d\n", ans);

    free(expression);
    return 0;
}
