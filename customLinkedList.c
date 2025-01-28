#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void swap(ListNode* a, ListNode* b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void bubbleSort(ListNode* start) {
    int swapped;
    ListNode* ptr1;
    ListNode* lptr = NULL;

    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->val > ptr1->next->val) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}

int findKthSmallest(ListNode* head1, ListNode* head2, int K) {
    ListNode* mergedHead = mergeLists(head1, head2);
    ListNode* current = mergedHead;
    int count = 1;

    while (current && count < K) {
        current = current->next;
        count++;
    }

    if (current) {
        return current->val;
    } else {
        return -1; 
    }
}

ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = createNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}


int main() {
    int size1, size2;
    printf("Enter total elements in linked list 1: ");
    scanf("%d", &size1);
    int arr1[size1];
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    ListNode* head1 = createList(arr1, size1);
    bubbleSort(head1);

    printf("Enter total elements in linked list 2: ");
    scanf("%d", &size2);
    int arr2[size2];
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    ListNode* head2 = createList(arr2, size2);
    bubbleSort(head2);

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    printf("\nEnter the kth value: ");
    int k;
    scanf("%d", &k);
    int result = findKthSmallest(head1, head2, k);
    if (result != -1)
        printf("The %dth smallest element is: %d\n", k, result);
    else
        printf("Invalid value of k.\n");
    return 0;
}
