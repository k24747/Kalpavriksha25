#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user {
    int id, age;
    char name[50];
} USER;

// Function to ensure the file exists
void ensureFileExists() {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        fp = fopen("users.txt", "w");
        if (fp == NULL) {
            printf("Error: Could not create file.\n");
            exit(1);
        }
    }
    fclose(fp);
}

// Add a new user
void add() {
    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    USER user;
    printf("Enter ID: ");
    scanf("%d", &user.id);
    getchar(); // Clear newline character from input buffer
    printf("Enter Name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0'; // Remove newline character
    printf("Enter Age: ");
    scanf("%d", &user.age);

    fprintf(fp, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(fp);
    printf("User added successfully.\n");
}

// Display all users
void display() {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    USER user;
    printf("---------------------------------------------------\n");
    printf("ID\tName\t\tAge\n");
    printf("---------------------------------------------------\n");
    while (fscanf(fp, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        printf("%d\t%-15s\t%d\n", user.id, user.name, user.age);
    }
    printf("---------------------------------------------------\n");
    fclose(fp);
}

// Search for a user by ID
void search() {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    int tid;
    printf("Enter ID to search: ");
    scanf("%d", &tid);

    USER user;
    int found = 0;
    while (fscanf(fp, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == tid) {
            printf("ID: %d\nName: %s\nAge: %d\n", user.id, user.name, user.age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("User with ID %d not found.\n", tid);
    }
    fclose(fp);
}

// Delete a user by ID
void delete() {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    int tid, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &tid);

    USER user;
    while (fscanf(fp, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == tid) {
            found = 1;
        } else {
            fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
        }
    }

    fclose(fp);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found) {
        printf("User with ID %d deleted successfully.\n", tid);
    } else {
        printf("User with ID %d not found.\n", tid);
    }
}

// Update a user by ID
void update() {
    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(fp);
        return;
    }

    int tid, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &tid);

    USER user;
    while (fscanf(fp, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) == 3) {
        if (user.id == tid) {
            found = 1;
            printf("Enter new Name: ");
            getchar(); // Clear newline
            fgets(user.name, sizeof(user.name), stdin);
            user.name[strcspn(user.name, "\n")] = '\0';
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(fp);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (found) {
        printf("User with ID %d updated successfully.\n", tid);
    } else {
        printf("User with ID %d not found.\n", tid);
    }
}

int main() {
    ensureFileExists();

    int choice;
    do {
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Update Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete();
                break;
            case 5:
                update();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
