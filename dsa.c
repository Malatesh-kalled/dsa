#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform inorder traversal and write to log file
void inorder(struct Node* root, FILE* logFile) {
    if (root == NULL) return;
    inorder(root->left, logFile);
    fprintf(logFile, "%d ", root->data);
    inorder(root->right, logFile);
}

// Function to perform preorder traversal and write to log file
void preorder(struct Node* root, FILE* logFile) {
    if (root == NULL) return;
    fprintf(logFile, "%d ", root->data);
    preorder(root->left, logFile);
    preorder(root->right, logFile);
}

// Function to perform postorder traversal and write to log file
void postorder(struct Node* root, FILE* logFile) {
    if (root == NULL) return;
    postorder(root->left, logFile);
    postorder(root->right, logFile);
    fprintf(logFile, "%d ", root->data);
}

int main() {
    struct Node* root = NULL;
    int i, num, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &num);

    srand(time(0)); // Initialize random seed

    printf("Enter the range: ");
    int minRange, maxRange;
    scanf("%d %d", &minRange, &maxRange);

    FILE* inorderFile = fopen("inorder.log", "w");

    FILE* preorderFile = fopen("preorder.log", "w");
    FILE* postorderFile = fopen("postorder.log", "w");

    if (inorderFile == NULL || preorderFile == NULL || postorderFile == NULL) {
        printf("Error opening log files.\n");
        return 1;
    }

    printf("Randomly generated numbers: ");
    for (i = 0; i < num; i++) {
        data = rand() % (maxRange - minRange + 1) + minRange;
        printf("%d ", data);
        root = insert(root, data);
    }

    fprintf(inorderFile, "Inorder traversal: ");
    inorder(root, inorderFile);

    fprintf(preorderFile, "Preorder traversal: ");
    preorder(root, preorderFile);

    fprintf(postorderFile, "Postorder traversal: ");
    postorder(root, postorderFile);

    fclose(inorderFile);
    fclose(preorderFile);
    fclose(postorderFile);

    return 0;
}
