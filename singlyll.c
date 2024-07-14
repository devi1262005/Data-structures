#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at the beginning of the linked list
void insertBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node in the linked list
void deleteBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node in the linked list
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position in the linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Function to delete the first occurrence of a specific value in the linked list
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Value not found in the list\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver program for singly linked list
int main() {
    struct Node* head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);

    printf("Singly Linked List: ");
    printList(head);

    // Example usage of different insertions and deletions
    insertBeginning(&head, 0);
    printf("After Inserting at the Beginning: ");
    printList(head);

    insertAtPosition(&head, 4, 2);
    printf("After Inserting at Position 2: ");
    printList(head);

    deleteBeginning(&head);
    printf("After Deleting at the Beginning: ");
    printList(head);

    deleteEnd(&head);
    printf("After Deleting at the End: ");
    printList(head);

    deleteAtPosition(&head, 1);
    printf("After Deleting at Position 1: ");
    printList(head);

    deleteByValue(&head, 2);
    printf("After Deleting Value 2: ");
    printList(head);

    return 0;
}
