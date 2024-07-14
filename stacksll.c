#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
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

// Function to push a node onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop a node from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int poppedValue = temp->data;
    free(temp);
    return poppedValue;
}

// Driver program for stack using linked list
int main() {
    struct Node* top = NULL;
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    printf("Popped from stack: %d\n", pop(&top));
    printf("Popped from stack: %d\n", pop(&top));

    return 0;
}

