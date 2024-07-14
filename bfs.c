#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node** neighbors;
    int numNeighbors;
    int visited;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->neighbors = NULL;
    newNode->numNeighbors = 0;
    newNode->visited = 0;
    return newNode;
}

void addEdge(struct Node* u, struct Node* v) {
    u->neighbors = realloc(u->neighbors, (u->numNeighbors + 1) * sizeof(struct Node*));
    if (u->neighbors == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    u->neighbors[u->numNeighbors++] = v;

    v->neighbors = realloc(v->neighbors, (v->numNeighbors + 1) * sizeof(struct Node*));
    if (v->neighbors == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    v->neighbors[v->numNeighbors++] = u;
}

void bfs(struct Node* start) {
    if (start == NULL) {
        return;
    }

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int front = 0, rear = 0;

    queue[rear++] = start;
    start->visited = 1;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        for (int i = 0; i < current->numNeighbors; i++) {
            struct Node* neighbor = current->neighbors[i];
            if (!neighbor->visited) {
                queue = realloc(queue, (rear + 1) * sizeof(struct Node*));
                if (queue == NULL) {
                    printf("Memory allocation failed\n");
                    exit(EXIT_FAILURE);
                }
                queue[rear++] = neighbor;
                neighbor->visited = 1;
            }
        }
    }

    free(queue);
}

int main() {
    struct Node* node1 = createNode(1);
    struct Node* node2 = createNode(2);
    struct Node* node3 = createNode(3);
    struct Node* node4 = createNode(4);
    struct Node* node5 = createNode(5);

    addEdge(node1, node2);
    addEdge(node1, node3);
    addEdge(node2, node4);
    addEdge(node3, node5);

    printf("BFS starting from node 1: ");
    bfs(node1);
    printf("\n");

    return 0;
}
