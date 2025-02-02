/*
Time Complexity:
Enqueue: O(1) – Inserting an element into the stack is done in constant time.
Dequeue: O(n) – In the worst case, the dequeue operation requires transferring all elements 
from one stack to another, which is linear in time.
Peek: O(n) – we might need to transfer elements to access the front, which takes linear time.
Size: O(1) – The size is stored directly and can be accessed in constant time.
Space Complexity:
O(n) – The space complexity is proportional to the number of elements in the stack as we're using one stack to hold the elements. 
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int *arr;
    int top;
    int capacity;
}Stack;

void initialize(Stack *s,int size){
    s->arr = (int *)malloc(size*sizeof(int));
    s->top = -1;
    s->capacity = size;
    return;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int isFull(Stack *s){
    return s->top == s->capacity-1;
}

void push(Stack *s,int value){
    if(isFull(s)){
        printf("Stack is already full\n");
        return;
    }
    s->arr[++(s->top)] = value;
    return;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is already empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peekRec(Stack *s){
    if(isEmpty(s)){
        printf("Queue is empty\n");
        return -1;
    }
    int x = pop(s);
    if (isEmpty(s)){
        push(s, x);
        return x;
    }
    int front = peekRec(s);
    push(s, x);
    return front;
}

int peek(Stack *s){
    return peekRec(s);
}

int Size(Stack *s){
    return s->top+1;
}

void enqueue(Stack *s,int value){
    push(s, value);
}

int dequeueRec(Stack *s){
    if(isEmpty(s)){
        printf("Queue is already empty\n");
        return -1;
    }
    int x = pop(s);
    if(isEmpty(s)){
        return x;
    }
    int item=dequeueRec(s);
    push(s, x);
    return item;
}

int dequeue(Stack *s){
    return dequeueRec(s);
}

int main(){
    Stack s;
    int size,operations,choice;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    initialize(&s, size);
    
    printf("Enter number of operations: ");
    scanf("%d", &operations);
    
    for(int i = 0;i < operations;i++){
        printf("Enter choice (1-Enqueue,2-Dequeue,3-Peek,4-Size,5-Exit): ");
        scanf("%d",&choice);
        
        if(choice == 1){
            int value;
            printf("Enter element to enqueue: ");
            scanf("%d", &value);
            enqueue(&s, value);
        }else if(choice == 2){
            int element = dequeue(&s);
            if(element != -1){
                printf("Deleted element is %d\n", element);
            }
        }else if(choice == 3){
            int peekElement = peek(&s);
            if(peekElement != -1){
                printf("Front element is %d\n", peekElement);
            }
        }else if(choice == 4){
            printf("Current size of queue: %d\n", Size(&s));
        }else if(choice == 5){
            break;
        }else{
            printf("Invalid choice! Try again.\n");
        }
    }
    free(s.arr);
    return 0;
}
