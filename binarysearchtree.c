#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }

    if (value < (*root)->value) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

void inorderTraversal(TreeNode* root, int minValue, int maxValue, FILE* file) {
    if (root != NULL) {
        inorderTraversal(root->left, minValue, maxValue, file);
        if (root->value >= minValue && root->value <= maxValue) {
            printf("%d ", root->value);
            fprintf(file, "%d ", root->value);
        }
        inorderTraversal(root->right, minValue, maxValue, file);
    }
}

void preorderTraversal(TreeNode* root, int minValue, int maxValue, FILE* file) {
    if (root != NULL) {
        if (root->value >= minValue && root->value <= maxValue) {
            printf("%d ", root->value);
            fprintf(file, "%d ", root->value);
        }
        preorderTraversal(root->left, minValue, maxValue, file);
        preorderTraversal(root->right, minValue, maxValue, file);
    }
}

void postorderTraversal(TreeNode* root, int minValue, int maxValue, FILE* file) {
    if (root != NULL) {
        postorderTraversal(root->left, minValue, maxValue, file);
        postorderTraversal(root->right, minValue, maxValue, file);
        if (root->value >= minValue && root->value <= maxValue) {
            printf("%d ", root->value);
            fprintf(file, "%d ", root->value);
        }
    }
}

void freeTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TreeNode* root = NULL;
    int i, numCount, minValue, maxValue;

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &numCount);

    printf("Enter the minimum value: ");
    scanf("%d", &minValue);

    printf("Enter the maximum value: ");
    scanf("%d", &maxValue);

    // Set the seed for the random number generator
    srand(time(NULL));

    printf("Random numbers:\n");

    // Generate random numbers and insert them into the binary tree
    for (i = 0; i < numCount; i++) {
        int randomNumber = (rand() % (maxValue - minValue + 1)) + minValue;
        insert(&root, randomNumber);
        printf("%d ", randomNumber);
    }

    // Open the file for writing
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        freeTree(root);  // Free the allocated memory before exiting
        return 1;
    }

    printf("\n\nPreorder traversal within range %d-%d: ", minValue, maxValue);
    preorderTraversal(root, minValue, maxValue, file);

    printf("\nPostorder traversal within range %d-%d: ", minValue, maxValue);
    postorderTraversal(root, minValue, maxValue, file);

    printf("\nInorder traversal within range %d-%d: ", minValue, maxValue);
    inorderTraversal(root, minValue, maxValue, file);

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        freeTree(root);  // Free the allocated memory before exiting
        return 1;
    }

    printf("\n\nInorder traversal from the file: ");
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d ", num);
    }

    // Close the file
    fclose(file);

    // Free the allocated memory
    freeTree(root);

    printf("\n\nTraversals saved to the file 'output.txt' and read back from the file.\n");

    return 0;
}
