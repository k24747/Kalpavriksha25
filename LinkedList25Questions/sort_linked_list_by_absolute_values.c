#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

Node *merge(Node *left, Node *right){
    if(!left) return right;
    if(!right) return left;
    Node *result = NULL;
    if(left->data < right->data){
        result = left;
        result->next = merge(left->next, right);
    }else{
        result = right;
        result->next = merge(left, right->next);        
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
    Node *left = NULL, *right = NULL;
    split(*head, &left, &right);
    mergeSort(&left);
    mergeSort(&right);
    *head = merge(left, right);
}

int main() {
    Node* head = NULL;
    int n, data;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertNode(&head, data);
    }

    mergeSort(&head);

    printf("Linked List: ");
    displayList(head);
    return 0;
}
