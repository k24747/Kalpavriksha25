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

void sort012(Node **head){
    Node *curr = *head;
    Node *head0 = createNode(0);
    Node *head1 = createNode(0);
    Node *head2 = createNode(0);
    Node *zero = head0, *one = head1, *two = head2;
    while(curr != NULL){
        if(curr->data == 0){
            zero->next = curr;
            zero = zero->next;
        }else if(curr->data == 1){
            one->next = curr;
            one = one->next;
        }else{
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }
    two->next = NULL;
    zero->next = (head1->next) ? head1->next : head2->next;
    one->next = head2->next;
    *head = head0->next;
    free(head0);
    free(head1);
    free(head2);
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

    sort012(&head);
    printf("Linked List: ");
    displayList(head);
    return 0;
}
