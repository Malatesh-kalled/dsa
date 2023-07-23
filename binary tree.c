#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into BST
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform in-order traversal of the tree
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int numNodes;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numNodes);

    int value;
    for (int i = 0; i < numNodes; i++) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Performing in-order traversal
    printf("In-order traversal: ");
    inorderTraversal(root);

    return 0;
}
