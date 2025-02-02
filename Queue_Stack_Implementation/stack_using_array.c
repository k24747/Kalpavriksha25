/*
Time Complexity:
Push: O(1).
Pop: O(1).
Peek: O(1).
Size: O(1).
Space Complexity:
O(n), where n is the number of elements in the stack.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int* arr;
    int top;
    int size;
}stack;

int isEmpty(stack* st)
{
    if(st->top == -1)
    return 1;

    return 0;
}

stack* push(stack* st)
{
    if(st->top == st->size)
    {
        st->size += st->size;
        st->arr = (int*)realloc(st->arr,sizeof(int)*st->size);
    }
    int value;
    scanf("%d",&value);
    st->arr[st->top+1] = value;
    st->top++;
    return st; 
}

void pop(stack* st)
{
    if(isEmpty(st) == 1)
    {
        printf("Stack Underflow\n");
        return;
    }
    st->top--;
}

void peek(stack* st)
{
    if(st->top == -1)
    {
        printf("Stack is Empty\n");
        return ;
    }
    printf("%d\n",st->arr[st->top]);
}

void size(stack* st)
{
    printf("Size of Stack is : %d\n",st->top+1);
}

int main()
{
    stack* st = (stack*)malloc(sizeof(stack));
    st->top = -1;
    st->size = 100;
    st->arr = (int*)malloc(100*sizeof(int));
    while(1)
    {
        int choice;
        printf("\nEnter the operation.\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.Size\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            st = push(st);
            break;
            case 2:
            pop(st);
            break;
            case 3:
            peek(st);
            break;
            case 4:
            if(isEmpty(st) == 1)
            printf("Stack is Empty\n");
            else
            printf("Stack is Not Empty\n");
            break;
            case 5:
            size(st);
            break;
            default:
            printf("Enter Valid Input");
        }
    }
    return 0;
}