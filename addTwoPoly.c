#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int expo;
    struct Node* next;
} Node;

Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    if (*head == NULL || (*head)->expo < expo) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL && temp->next->expo >= expo) {
            temp = temp->next;
        }
        if (temp->expo == expo) {
            temp->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo > poly2->expo) {
            insertNode(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            insertNode(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                insertNode(&result, sumCoeff, poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return result;
}

void printPolynomial(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->expo);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

Node* inputPolynomial() {
    Node* poly = NULL;
    int n;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int coeff, expo;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        insertNode(&poly, coeff, expo);
    }

    return poly;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    printf("Input for Polynomial 1:\n");
    poly1 = inputPolynomial();

    printf("Input for Polynomial 2:\n");
    poly2 = inputPolynomial();

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
