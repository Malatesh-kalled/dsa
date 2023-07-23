#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void generateRandomNumbers(Node* root, int rangeStart, int rangeEnd, int maxNumbers, FILE* file) {
    if (root == NULL || maxNumbers == 0) {
        return;
    }

    generateRandomNumbers(root->left, rangeStart, rangeEnd, maxNumbers, file);

    int randomNum = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
    fprintf(file, "%d\n", randomNum);
    maxNumbers--;

    generateRandomNumbers(root->right, rangeStart, rangeEnd, maxNumbers, file);
}

void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main() {
    srand(time(NULL));

    int rangeStart, rangeEnd, maxNumbers;
    printf("Enter the range start: ");
    scanf("%d", &rangeStart);
    printf("Enter the range end: ");
    scanf("%d", &rangeEnd);
    printf("Enter the maximum number of random values to generate: ");
    scanf("%d", &maxNumbers);

    Node* root = NULL;
    FILE* file = fopen("random_numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (maxNumbers > 0) {
        int randomNum = rand() % (rangeEnd - rangeStart + 1) + rangeStart;
        fprintf(file, "%d\n", randomNum);
        root = insertNode(root, randomNum);
        maxNumbers--;
    }

    fclose(file);

    printf("Random numbers have been generated and stored in 'random_numbers.txt'.\n");

    deleteTree(root);

    return 0;
}
