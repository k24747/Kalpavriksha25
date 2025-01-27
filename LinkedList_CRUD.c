#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int val;
    struct Node *next;
}Node;

void insertAtEnd(Node **headref, int value){
    if(*headref == NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = value;
        newNode->next = NULL;
        *headref = newNode; 
        return;
    }

    Node *temp = (*headref);
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = NULL;
    temp->next = newNode;
}

void insertAtBeginning(Node **headref, int value){
    if(*headref == NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = value;
        newNode->next = NULL;
        *headref = newNode; 
        return;
    }
    Node *newTemp = (Node *)malloc(sizeof(Node));
    newTemp->val = value;
    newTemp->next = (*headref);
    *headref = newTemp;
}

void insertAtPosition(Node **headref,int position, int value){
    if(*headref == NULL){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = value;
        newNode->next = NULL;
        *headref = newNode; 
        return;
    }
     if (position < 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(headref, value);
        return;
    }
    Node *temp = *headref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->val = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void updateAtPosition(Node **headref, int position, int value){
    if(*headref == NULL || position < 1){
        printf("Invalid Position\n");
        return;
    }
    Node *temp = *headref;
    int n = 1, pos = 1;
    while(temp != NULL && pos < position){
        pos++;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Invalid position\n");
        return;
    }
    temp->val = value;
}

void deleteAtBeginning(Node **headref){
    if (*headref == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node *temp = (*headref)->next;
    free(*headref);
    *headref = temp;
}

void deleteAtEnd(Node **headref){
    if (*headref == NULL) {
        printf("Invalid position\n");
        return;
    }
    if ((*headref)->next == NULL) {
        free(*headref);
        *headref = NULL;
        return;
    }
    Node *temp = *headref;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(Node **headref, int position){
    if (position < 1 || *headref == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node *temp = *headref;
    if(position == 1){
        deleteAtBeginning(&(*headref));
        return;
    }
    int pos = 1;
    while(pos < position && temp->next != NULL){
        temp = temp->next;
        pos++;
    }
    if (temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    Node *fwd = temp->next->next;
    free(temp->next);
    temp->next = fwd;
}

void display(Node *headref){
    Node *temp = headref;
    while(temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node *head = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int choice;
        scanf("%d", &choice);

        if(choice == 1){
            int value;
            scanf("%d", &value);
            insertAtEnd(&head, value);
        }else if(choice == 2){
            int value;
            scanf("%d", &value);
            insertAtBeginning(&head, value);
        }else if(choice == 3){
            int pos, value;
            scanf("%d %d", &pos, &value);
            insertAtPosition(&head, pos, value);
        }else if(choice == 4){
            display(head);
        }else if(choice == 5){
            int position, newValue;
            scanf("%d %d", &position, &newValue);
            updateAtPosition(&head, position, newValue);
        }else if(choice == 6){
            deleteAtBeginning(&head);
        }else if(choice == 7){
            deleteAtEnd(&head);
        }else if(choice == 8){
            int position;
            scanf("%d", &position);
            deleteAtPosition(&head, position);
        }else{
            printf("Invalid operation");
            break;
        }
    }
    Node *curr = head;
    Node *nextNode;
    while(curr != NULL){
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
    head = NULL;
    return 0;
}