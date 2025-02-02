#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int *arr;
    int top;
    int capacity;
} Stack;

void initialize(Stack *s, int size){
    s->arr = (int *) malloc(size * sizeof(int));
    s->top = -1;
    s->capacity = size;
    return;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int isFull(Stack *s){
    return s->top == s->capacity - 1;
}

void push(Stack *s, int value){
    if (isFull(s)) {
        printf("Stack is already full\n");
        return;
    }
    s->arr[++(s->top)] = value;
    return;
}

int pop(Stack *s){
    if (isEmpty(s)) {
        printf("Stack is already empty\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

typedef struct Queue{
    Stack s1, s2;
} Queue;

void initializeQueue(Queue *q, int size){
    initialize(&q->s1, size);
    initialize(&q->s2, size);
}

void enqueue(Queue *q, int value){
    push(&q->s1, value);
}

int dequeue(Queue *q){
    if(isEmpty(&q->s1) && isEmpty(&q->s2)){
        printf("Queue is already empty\n");
        return -1;
    }
    if(isEmpty(&q->s2)){
        while(!isEmpty(&q->s1)){
            push(&q->s2, pop(&q->s1));
        }
    }
    return pop(&q->s2);
}

int peek(Queue *q){
    if(isEmpty(&q->s1) && isEmpty(&q->s2)){
        printf("Queue is empty\n");
        return -1;
    }
    if(isEmpty(&q->s2)){
        while(!isEmpty(&q->s1)){
            push(&q->s2, pop(&q->s1));
        }
    }
    return q->s2.arr[q->s2.top];
}

int Size(Queue *q){
    return q->s1.top + 1 + q->s2.top + 1;
}

int main(){
    Queue q;
    int size, operations, choice;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    initializeQueue(&q, size);
    
    printf("Enter number of operations: ");
    scanf("%d", &operations);
    
    for(int i = 0; i < operations; i++){
        printf("Enter choice (1-Enqueue, 2-Dequeue, 3-Peek, 4-Size, 5-Exit): ");
        scanf("%d", &choice);
        
        if(choice == 1){
            int value;
            printf("Enter element to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
        } else if(choice == 2){
            int element = dequeue(&q);
            if(element != -1){
                printf("Deleted element is %d\n", element);
            }
        } else if (choice == 3) {
            int peekElement = peek(&q);
            if (peekElement != -1) {
                printf("Front element is %d\n", peekElement);
            }
        } else if(choice == 4){
            printf("Current size of queue: %d\n", Size(&q));
        } else if(choice == 5){
            break;
        } else{
            printf("Invalid choice! Try again.\n");
        }
    }
    free(q.s1.arr);
    free(q.s2.arr);
    return 0;
}
