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

void enqueue(Queue *q,int value){
    if(isFull(q)){
        printf("Queue is already full\n");
        return;
    }
    if(isEmpty(q)){
        q->front=0;
    }
    q->arr[++(q->rear)]=value;
    return;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is already empty\n");
        return -1;
    }
    int element=q->arr[q->front];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }else{
        q->front++;
    }
    return element;
}

typedef struct Stack{
    Queue q1,q2;
    int capacity;
}Stack;

void initializeStack(Stack *s,int size){
    initialize(&s->q1,size);
    initialize(&s->q2,size);
    s->capacity=size;
}

void push(Stack *s,int value){
    enqueue(&s->q2,value);
    while(!isEmpty(&s->q1)){
        enqueue(&s->q2,dequeue(&s->q1));
    }
    Queue temp=s->q1;
    s->q1=s->q2;
    s->q2=temp;
}

int pop(Stack *s){
    if(isEmpty(&s->q1)){
        printf("Stack is already empty\n");
        return -1;
    }
    return dequeue(&s->q1);
}

int peek(Stack *s){
    if(isEmpty(&s->q1)){
        printf("Stack is empty\n");
        return -1;
    }
    return s->q1.arr[s->q1.front];
}

int Size(Stack *s){
    return s->q1.rear - s->q1.front + 1;
}

int main(){
    Stack s;
    int size,operations,choice;
    printf("Enter size of stack: ");
    scanf("%d",&size);
    initializeStack(&s,size);
    
    printf("Enter number of operations: ");
    scanf("%d",&operations);
    
    for(int i=0;i<operations;i++){
        printf("Enter choice (1-Push,2-Pop,3-Peek,4-Size,5-Exit): ");
        scanf("%d",&choice);
        
        if(choice==1){
            int value;
            printf("Enter element to push: ");
            scanf("%d",&value);
            push(&s,value);
        }else if(choice==2){
            int element=pop(&s);
            if(element!=-1){
                printf("Deleted element is %d\n",element);
            }
        }else if(choice==3){
            int peekElement=peek(&s);
            if(peekElement!=-1){
                printf("Top element is %d\n",peekElement);
            }
        }else if(choice==4){
            printf("Current size of stack: %d\n",Size(&s));
        }else if(choice==5){
            break;
        }else{
            printf("Invalid choice! Try again.\n");
        }
    }
    free(s.q1.arr);
    free(s.q2.arr);
    return 0;
}
