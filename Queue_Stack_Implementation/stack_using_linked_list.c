#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node;

Node *createNode(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->val = value;
    return newNode;
}

void push(Node **head, Node **top){
    int value;
    printf("Enter value : ");
    scanf("%d", &value);
    Node *newNode = createNode(value);
    if(*head == NULL){
        *head = newNode;
        *top = *head;
        return;
    }
    (*top)->next = newNode;
    *top = (*top)->next;
    return;
}

void pop(Node **head, Node **top){
    if(*head == NULL || (*head)->next == NULL){
        *head = NULL;
        *top = NULL;
        return;
    }
    Node *temp = *head;
    while(temp->next != *top){
        temp = temp->next;
    }
    temp->next = NULL;
    free(*top);
    *top = temp;
}

void peek(Node *top){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", top->val);
}

void isEmpty(Node *head){
    if(head == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is not empty\n");
}

void size(Node *head, Node *top){
    Node *temp = head;
    int count = 1;
    while(temp != top){
        count++;
        temp = temp->next;
    }
    printf("Size is %d\n", count);
}

int main()
{
    Node *head = NULL, *top = NULL;
    int choice, operations;
    scanf("%d", &operations);
    
    for(int i = 0; i < operations; i++){
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            push(&head, &top);
            break;
            case 2:
            pop(&head, &top);
            break;
            case 3:
            peek(top);
            break;
            case 4:
            isEmpty(head);
            break;
            case 5:
            size(head, top);
            break;
            default:
            break;
        }
    }
    return 0;
}