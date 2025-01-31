#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue{
    int *array;
    int front;
    int rear;
    int capacity;
}Queue;

void initializeQueue(Queue *q, int size){
    q->array = (int *)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->capacity = size;
}

int isEmpty(Queue *q){
    return (q->rear == -1 || q->front > q->rear);
}

int isFull(Queue *q){
    return (q->rear == q->capacity - 1);
}

void enqueue(Queue *q, int value){
    if(isFull(q)){
        printf("Queue is already full.\n");
        return;
    }
    if(isEmpty(q)){
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->array[q->rear] = value;
}

void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is already empty.\n");
        return;
    }
    q->front++;
    if(q->front > q->rear){
        printf("Queue Underflow\n");
        q->front = -1;
        q->rear = -1;
    }
}

int peek(Queue *q){
    if(isEmpty(q)){
        printf("Queue is already empty.\n");
        return -1;
    }
    return q->array[q->rear];
}

void Size(Queue *q){
    if(isEmpty(q)){
        printf("Queue is already empty.\n");
        return;
    }
    printf("Queue size is %d\n", (q->rear - q->front + 1));
}

int main(){
    Queue q;
    int size, operations, choice;
    printf("Enter Queue size : ");
    scanf("%d", &size);
    initializeQueue(&q, size);
    
    printf("Enter number of operations : ");
    scanf("%d", &operations);
    for(int i = 0; i < operations; i++){
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                int value;
                printf("Enter value : ");
                scanf("%d", &value);
                enqueue(&q, value);
            }
            break;
            case 2:
                dequeue(&q);
                break;
            case 3:{
                int value = peek(&q);
                if (value != -1)
                    printf("Peek element is : %d\n", value);
            }
            break;
            case 4:
                printf(isEmpty(&q) ? "Empty\n" : "Not Empty\n");
                break;
            case 5:
                Size(&q);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    free(q.array);
    return 0;
}
