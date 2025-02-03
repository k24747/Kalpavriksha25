#include <stdio.h>
#include <stdlib.h>

typedef struct HashMap
{
    int key;
    int value;
    struct HashMap *next;
} HashMap;

HashMap *createNode(int Key, int Value)
{
    HashMap *newNode = (HashMap *)malloc(sizeof(HashMap));
    newNode->key = Key;
    newNode->value = Value;
    newNode->next = NULL;
    return newNode;
}

HashMap *findNode(HashMap *head, int Key)
{
    while (head != NULL)
    {
        if (head->key == Key)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void insert(HashMap **head, int Key, int Value)
{
    HashMap *existingNode = findNode(*head, Key);
    if (existingNode)
    {
        existingNode->value = Value;
        return;
    }
    HashMap *newNode = createNode(Key, Value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    HashMap *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void display(HashMap *head)
{
    while (head != NULL)
    {
        if (head->next != NULL)
        {
            printf("(%d, %d) -> ", head->key, head->value);
        }
        else
        {
            printf("(%d, %d)", head->key, head->value);
        }
        head = head->next;
    }
    printf("\n");
}

void delete(HashMap **head, int Key)
{
    HashMap *curr = *head, *prev = NULL;
    while (curr != NULL)
    {
        if (curr->key == Key)
        {
            if (curr == *head)
            {
                *head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            printf("Key %d deleted\n", Key);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key %d not found\n", Key);
}

void search(HashMap **head, int Key)
{
    HashMap *foundNode = findNode(*head, Key);
    if (foundNode)
    {
        printf("Value: %d\n", foundNode->value);
    }
    else
    {
        printf("No key present\n");
    }
}

int main()
{
    HashMap *head = NULL;
    int choice;
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int Key, Value;
            printf("Enter Key : ");
            scanf("%d", &Key);
            printf("Enter Value : ");
            scanf("%d", &Value);
            insert(&head, Key, Value);
        }
        else if (choice == 2)
        {
            int Key;
            printf("Enter Key : ");
            scanf("%d", &Key);
            search(&head, Key);
        }
        else if (choice == 3)
        {
            int Key;
            printf("Enter key : ");
            scanf("%d", &Key);
            delete (&head, Key);
        }
        else if (choice == 4)
        {
            display(head);
        }
        else if (choice == 5)
        {
            printf("Exiting Program\n");
        }
    } while (choice != 5);
    return 0;
}