#include<stdio.h>
#include<stdlib.h>

typedef struct listNode
{
    int val;
    struct listNode* next;
}listNode;

typedef struct queue
{
    listNode* front;
    listNode* rear;
    int size;
}queue;

int isEmpty(queue* q)
{
    return (q->front == NULL);
}

void enqueue(queue* q)
{
    
    listNode* node = (listNode*)malloc(sizeof(listNode));
    if(node == NULL)
    {
        printf("Memory Overload\n");
        return;
    }
    int value;
    scanf("%d",&value);
    node->val = value;
    node->next = NULL;
    q->size++;
    if(isEmpty(q))
    {
        q->front = node;
        q->rear = node;
        return;
    }

    (q->rear)->next = node;
    (q->rear) = (q->rear)->next;
}

void dequeue(queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow\n");
        return;
    }
    q->size--;
    if(q->front == q->rear)
    {
        q->front = NULL;
        q->rear = NULL;
        return;
    }
    listNode* temp = q->front;
    q->front = (q->front)->next;
    free(temp);   
}

void peek(queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("%d\n",(q->front)->val);
}

void size(queue* q)
{
    printf("%d\n",q->size);
}

int main()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    while(1)
    {
        printf("Enter the Operation:\n1.Enqueue\n2.Dequeue\n3.peek\n4.isEmpty\n5.size\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue(q);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                if(isEmpty(q))
                    printf("Queue is Empty\n");
                else
                    printf("Queue is not Empty\n");
                break;
            case 5:
                size(q);
                break;
            default:
                printf("Invalid Input\n");
                break;        
        }
    }
    return 0;
}