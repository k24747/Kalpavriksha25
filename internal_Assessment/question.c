#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int id;
    char *condition;
    struct Node* next;
}Node;

int idExists(Node *head, int id){
    while(head){
        if(head->id == id) return 1;
        head = head->next;
    }
    return 0;
}

int isValid(char *condi){
    return (strcmp(condi, "Critical") == 0 || strcmp(condi, "Serious") == 0 || strcmp(condi, "Stable") == 0);
}

Node *createNode(int id, char *condi){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->condition = (char *)malloc(101 * sizeof(char));
    strcpy(newNode->condition, condi);
    newNode->next = NULL;
    return newNode;
}

void createLinkedList(Node **head, int id, char *condi){
    if(idExists(*head, id)){
        printf("Error: ID %d already exists!\n", id);
        return;
    }
    if(!isValid(condi)){
        printf("Error: Invalid condition '%s'. Allowed values: Critical, Serious, Stable\n", condi);
        return;
    }
    Node *newNode = createNode(id, condi);
    if(*head == NULL){
        *head = newNode;
        (*head)->next = NULL;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node *head){
    while(head != NULL){
        printf("%d %s\n", head->id, head->condition);
        head = head->next;
    }
}

Node *merge(Node *left, Node *right){
    if(left == NULL) return right;
    if(right == NULL) return left;
    Node *result = NULL;
    if(strcmp(left->condition, "Critical") == 0 || strcmp(right->condition, "Critical") == 0){
        if(strcmp(left->condition, "Critical") == 0){
            result = left;
            result->next = merge(left->next, right);
        }else{
            result = right;
            result->next = merge(left, right->next);
        }
    }else if(strcmp(left->condition, "Serious") == 0 || strcmp(right->condition, "Serious") == 0){
        if(strcmp(left->condition, "Serious") == 0){
            result = left;
            result->next = merge(left->next, right);
        }else{
            result = right;
            result->next = merge(left, right->next);
        }
    }else{
        if(strcmp(left->condition, "Stable") == 0){
            result = left;
            result->next = merge(left->next, right);
        }else{
            result = right;
            result->next = merge(left, right->next);
        }
    }
    return result;
}

void split(Node *head, Node **left, Node **right){
    if(head == NULL || head->next == NULL){
        *left = head;
        *right = NULL;
        return;
    }
    Node *slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

void mergeSort(Node **head){
    if(*head == NULL || (*head)->next == NULL){
        return;
    }
    Node *left, *right;
    split(*head, &left, &right);
    mergeSort(&left);
    mergeSort(&right);
    *head = merge(left, right); 
}

void freeList(Node *head){
    while(head){
        Node *temp = head;
        head = head->next;
        free(temp->condition);
        free(temp);
    }
}


int main(){
    Node *head = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int id;
        char *condi = (char *)malloc(101 * sizeof(char));
        scanf("%d %100s", &id, condi);
        createLinkedList(&head, id, condi);
        free(condi);
    }
    mergeSort(&head);
    display(head);
    freeList(head);
    return 0;
}