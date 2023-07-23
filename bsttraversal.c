#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

void inorderTraversal(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left, file);
    fprintf(file, "%d ", root->data);
    inorderTraversal(root->right, file);
}

void preorderTraversal(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    fprintf(file, "%d ", root->data);
    preorderTraversal(root->left, file);
    preorderTraversal(root->right, file);
}

void postorderTraversal(Node* root, FILE* file) {
    if (root == NULL) {
        return;
    }

    postorderTraversal(root->left, file);
    postorderTraversal(root->right, file);
    fprintf(file, "%d ", root->data);
}

void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;

    FILE* inputFile = fopen("random_numbers.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file 'random_numbers.txt'.\n");
        return 1;
    }

    int value;
    while (fscanf(inputFile, "%d", &value) != EOF) {
        root = insertNode(root, value);
    }

    fclose(inputFile);

    FILE* inorderFile = fopen("inorder.txt", "w");
    if (inorderFile == NULL) {
        printf("Error opening file 'inorder.txt'.\n");
        deleteTree(root);
        return 1;
    }

    FILE* preorderFile = fopen("preorder.txt", "w");
    if (preorderFile == NULL) {
        printf("Error opening file 'preorder.txt'.\n");
        deleteTree(root);
        fclose(inorderFile);
        return 1;
    }

    FILE* postorderFile = fopen("postorder.txt", "w");
    if (postorderFile == NULL) {
        printf("Error opening file 'postorder.txt'.\n");
        deleteTree(root);
        fclose(inorderFile);
        fclose(preorderFile);
        return 1;
    }

    // Perform inorder traversal and store the result in "inorder.txt"
    inorderTraversal(root, inorderFile);
    fclose(inorderFile);

    // Perform preorder traversal and store the result in "preorder.txt"
    preorderTraversal(root, preorderFile);
    fclose(preorderFile);

    // Perform postorder traversal and store the result in "postorder.txt"
    postorderTraversal(root, postorderFile);
    fclose(postorderFile);

    printf("Traversals have been performed and stored in 'inorder.txt', 'preorder.txt', and 'postorder.txt'.\n");

    deleteTree(root);

    return 0;
}
