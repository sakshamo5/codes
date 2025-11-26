#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int *parent, *rankArr;

void makeSet(int v) {
    parent[v] = v;
    rankArr[v] = 0;
}

int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (rankArr[a] < rankArr[b])
            parent[a] = b;
        else if (rankArr[a] > rankArr[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rankArr[a]++;
        }
    }
}

int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->w - edgeB->w;
}

int kruskal(Edge edges[], int e, int n) {
    qsort(edges, e, sizeof(Edge), compareEdges);

    parent = (int *)malloc(n * sizeof(int));
    rankArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        makeSet(i);

    int cost = 0, count = 0;
    for (int i = 0; i < e && count < n - 1; i++) {
        Edge edge = edges[i];
        if (findSet(edge.u) != findSet(edge.v)) {
            cost += edge.w;
            unionSets(edge.u, edge.v);
            count++;
        }
    }

    free(parent);
    free(rankArr);

    return cost;
}

int main() {
    int n = 4;
    int e = 5;
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int minCost = kruskal(edges, e, n);
    printf("Minimum cost of spanning tree: %d\n", minCost);

    return 0;
}
