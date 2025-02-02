#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;

void initialize(Queue *q,int size){
    q->arr=(int *)malloc(size*sizeof(int));
    q->front=-1;
    q->rear=-1;
    q->capacity=size;
    return;
}

int isEmpty(Queue *q){
    return q->front==-1;
}

int isFull(Queue *q){
    return q->rear==q->capacity-1;
}

void push(Queue *q,int value){
    if(isFull(q)){
        printf("Stack is already full\n");
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->arr[++(q->rear)]=value;
    return;
}

int pop(Queue *q){
    if(isEmpty(q)){
        printf("Stack is already empty\n");
        return -1;
    }
    int element=q->arr[q->rear--];
    if(q->rear==-1){
        q->front=-1;
    }
    return element;
}

int peek(Queue *q){
    if(isEmpty(q)){
        printf("Stack is empty\n");
        return -1;
    }
    return q->arr[q->rear];
}

int Size(Queue *q){
    if(isEmpty(q)){
        return 0;
    }
    return q->rear-q->front+1;
}

int main(){
    Queue q;
    int size,operations,choice;
    printf("Enter size of stack: ");
    scanf("%d",&size);
    initialize(&q,size);
    
    printf("Enter number of operations: ");
    scanf("%d",&operations);
    
    for(int i=0;i<operations;i++){
        printf("Enter choice (1-Push,2-Pop,3-Peek,4-Size,5-Exit): ");
        scanf("%d",&choice);
        
        if(choice==1){
            int value;
            printf("Enter element to push: ");
            scanf("%d",&value);
            push(&q,value);
        }else if(choice==2){
            int element=pop(&q);
            if(element!=-1){
                printf("Deleted element is %d\n",element);
            }
        }else if(choice==3){
            int peekElement=peek(&q);
            if(peekElement!=-1){
                printf("Top element is %d\n",peekElement);
            }
        }else if(choice==4){
            printf("Current size of stack: %d\n",Size(&q));
        }else if(choice==5){
            break;
        }else{
            printf("Invalid choice! Try again.\n");
        }
    }
    free(q.arr);
    return 0;
}
