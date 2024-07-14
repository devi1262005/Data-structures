#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int array[MAX_SIZE];
    int front, rear;
};

// Function to initialize a queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));

    return 0;
}
