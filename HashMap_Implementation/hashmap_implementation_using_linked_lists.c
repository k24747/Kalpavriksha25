#include <stdio.h>
#include <stdlib.h>

int is_validChoice(int choice){
    if(choice>=1 && choice<=5){
        return 1;
    }

    return 0;
}

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node* table[10];
} HashMap;

int hash(int key) {
    return key % 10;
}

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void initialize_HashMap(HashMap* map) {
    for (int i = 0; i < 10; i++) {
        map->table[i] = NULL;
    }
}

void insert(HashMap* map, int key, int value) {
    int index = hash(key);
    Node* current = map->table[index];

    while (current != NULL) {
        if (current->key == key) {
            current->value = value; 
            return;
        }
        current = current->next;
    }

    Node* newNode = createNode(key, value);
    if (map->table[index] == NULL) {
        map->table[index] = newNode;
    }
    else {
        current = map->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;  
    }
}


int search(HashMap* map, int key) {
    int index = hash(key);
    Node* current = map->table[index];

    while (current != NULL){
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}

void delete(HashMap* map, int key) {
    int index = hash(key);
    Node* current = map->table[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                map->table[index] = current->next;
            } 
            else {
                prev->next = current->next;
            }
            free(current);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Key %d not found.\n", key);
}

void display(HashMap* map) {
    printf("Hash Table:\n");
    for (int i = 0; i < 10; i++) {
        Node* current = map->table[i];
        if (current != NULL) {
            printf("Index %d: ", i);
            while (current != NULL) {
                if(current->next==NULL){
                    printf("(%d, %d)", current->key, current->value);
                }
                else{
                    printf("(%d, %d)->", current->key, current->value);
                }
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main() {
    HashMap map;
    initialize_HashMap(&map);
    int choice, key, value;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Insert (Put)\n");
        printf("2. Search (Get)\n");
        printf("3. Delete (Remove)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        if(!is_validChoice(choice)){
            printf("Enter a valid choice!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                if(key<0){
                    printf("Key cannot be negative!\n");
                    break;
                }
                printf("Enter value: ");
                scanf("%d", &value);
                if(value<0){
                    printf("Value cannot be negative!\n");
                    break;
                }
                insert(&map, key, value);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(&map, key);
                if (value == -1) {
                    printf("Key not found.\n");
                } 
                else {
                    printf("Value: %d\n", value);
                }
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(&map, key);
                break;

            case 4:
                display(&map);
                break;

            case 5:
                printf("Exit...\n");
                return 0;

            default:
                printf("Enter a valid choice!\n");
                break;
        }
    }

    return 0;
}