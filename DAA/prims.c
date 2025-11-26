#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int prims(int **graph, int n) {
    bool *visited = (bool *)calloc(n, sizeof(bool));
    visited[0] = true;  // Start from vertex 0
    int edges = 0, cost = 0;

    while (edges < n - 1) {
        int min = INT_MAX, u = -1, v = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] != 0 && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (v != -1) {
            visited[v] = true;
            cost += min;
            edges++;
        }
    }
    free(visited);
    return cost;
}

int main() {
    int n = 5;
    int **graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    // Sample graph adjacency matrix (0 means no edge)
    int temp[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = temp[i][j];

    int minCost = prims(graph, n);
    printf("Minimum cost spanning tree: %d\n", minCost);

    for (int i = 0; i < n; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
