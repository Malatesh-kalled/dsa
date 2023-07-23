#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to create the adjacency matrix from a file
void createAdjacencyMatrixFromFile(const char* filename, int** matrix, int numNodes) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int src, dest;
    while (fscanf(file, "%d %d", &src, &dest) != EOF) {
        if (src >= 1 && src <= numNodes && dest >= 1 && dest <= numNodes) {
            matrix[src][dest] = 1;
            matrix[dest][src] = 1; // Assuming an undirected graph
        }
    }

    fclose(file);
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(int** matrix, int numNodes) {
    printf("Adjacency Matrix:\n");
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Number of nodes in the graph
    int numNodes = 0;

    // Reading the number of nodes from the file
    FILE* file = fopen("graph.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(file, "%d", &numNodes);
    fclose(file);

    // Creating the adjacency matrix
    int** adjacencyMatrix = (int**)malloc((numNodes + 1) * sizeof(int*));
    for (int i = 0; i <= numNodes; i++) {
        adjacencyMatrix[i] = (int*)calloc((numNodes + 1), sizeof(int));
    }

    // Populating the adjacency matrix from the file
    createAdjacencyMatrixFromFile("graph.txt", adjacencyMatrix, numNodes);

    // Printing the adjacency matrix
    printAdjacencyMatrix(adjacencyMatrix, numNodes);

    // Freeing memory
    for (int i = 0; i <= numNodes; i++) {
        free(adjacencyMatrix[i]);
    }
    free(adjacencyMatrix);

    return 0;
}
