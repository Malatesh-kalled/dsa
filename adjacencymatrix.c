#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void dfs(int adjList[MAX_VERTICES][MAX_VERTICES], int vertex, bool visited[], int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    visited[vertex] = true;
    for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
        if (adjList[vertex][neighbor] == 1 && !visited[neighbor]) {
            adjacencyMatrix[vertex][neighbor] = 1;
            adjacencyMatrix[neighbor][vertex] = 1;
            dfs(adjList, neighbor, visited, adjacencyMatrix, numVertices);
        }
    }
}

void generateAdjacencyMatrix(int adjList[MAX_VERTICES][MAX_VERTICES], int numVertices, int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES]) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < numVertices; ++i) {
        visited[i] = false;
    }

    for (int vertex = 0; vertex < numVertices; ++vertex) {
        if (!visited[vertex]) {
            dfs(adjList, vertex, visited, adjacencyMatrix, numVertices);
        }
    }
}

int main() {
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int adjList[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency list:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            scanf("%d", &adjList[i][j]);
        }
    }

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {{0}};

    generateAdjacencyMatrix(adjList, numVertices, adjacencyMatrix);

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
