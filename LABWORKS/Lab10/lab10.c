#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PROPS 3

struct Edge {
    int src, dest, distance;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));

    return graph;
}

int minDistance(int distance[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX_PROPS; v++) {
        if (mstSet[v] == 0 && distance[v] < min) {
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int props[MAX_PROPS][MAX_PROPS]) {
    printf("Minimum Spanning Tree:\n");
    printf("Prop \tDistance\n");
    for (int i = 1; i < MAX_PROPS; i++)
        printf("%d - %d \t%d \n", parent[i], i, props[i][parent[i]]);
}

void primMST(int props[MAX_PROPS][MAX_PROPS]) {
    int parent[MAX_PROPS];
    int distance[MAX_PROPS];
    int mstSet[MAX_PROPS];

    for (int i = 0; i < MAX_PROPS; i++) {
        distance[i] = INT_MAX;
        mstSet[i] = 0;
    }

    distance[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < MAX_PROPS - 1; count++) {
        int u = minDistance(distance, mstSet);

        mstSet[u] = 1;

        for (int v = 0; v < MAX_PROPS; v++) {
            if (props[u][v] && mstSet[v] == 0 && props[u][v] < distance[v]) {
                parent[v] = u;
                distance[v] = props[u][v];
            }
        }
    }

    printMST(parent, props);
}

int myComp(const void* a, const void* b) {
    return ((struct Edge*)a)->distance - ((struct Edge*)b)->distance;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(struct Graph* graph) {
    int* parent = (int*)malloc(MAX_PROPS * sizeof(int));
    for (int i = 0; i < MAX_PROPS; i++)
        parent[i] = -1;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < graph->E; i++) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x != y) {
            printf("%d - %d \t%d \n", graph->edge[i].src, graph->edge[i].dest, graph->edge[i].distance);
            Union(parent, x, y);
        }
    }
}

int main() {
    int propDistances[MAX_PROPS][MAX_PROPS];
    int choice;

    printf("Enter the distances between props (0 for no connection):\n");
    for (int i = 0; i < MAX_PROPS; i++) {
        for (int j = 0; j < MAX_PROPS; j++) {
            scanf("%d", &propDistances[i][j]);
        }
    }

    struct Graph* userGraph = createGraph(MAX_PROPS, MAX_PROPS * (MAX_PROPS - 1) / 2);

    int k = 0;
    for (int i = 0; i < MAX_PROPS; i++) {
        for (int j = i + 1; j < MAX_PROPS; j++) {
            userGraph->edge[k].src = i;
            userGraph->edge[k].dest = j;
            userGraph->edge[k].distance = propDistances[i][j];
            k++;
        }
    }

    printf("Choose the MST algorithm:\n");
    printf("1. Prim's Algorithm\n");
    printf("2. Kruskal's Algorithm\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            primMST(propDistances);
            break;
        case 2:
            kruskalMST(userGraph);
            break;
        defaulft:
            printf("Invalid choice\n");
    }

    return 0;
}
