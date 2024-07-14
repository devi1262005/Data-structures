#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given key
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node with a given key into the BST
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, return a new node
    if (root == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    // Return the unchanged node pointer
    return root;
}

// Function to perform inorder traversal of the BST
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Driver program to test Binary Search Tree functions
int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the constructed BST is: ");
    inOrder(root);
    printf("\n");

    return 0;
}
