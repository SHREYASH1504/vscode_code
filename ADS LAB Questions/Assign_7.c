#include<stdio.h>
#include <stdlib.h>
#define INT_MAX 99
int n;

// Node structure for vertex, its weight and next node pointer
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// A graphM structure to hold number of vertices and array of list of nodes
struct Graph {
    int n;
    struct Node** listOfNodes;
};

// A create node function which will create a node with given vertex and weight
struct Node* create(int vertex, int weight) {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->vertex = vertex;
    new->weight = weight;
    new->next = NULL;
    return new;
}

struct Graph* makeGraph(int n) {
    struct Graph* graphM = (struct Graph*)malloc(sizeof(struct Graph));
    graphM->n = n;
    graphM->listOfNodes = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        graphM->listOfNodes[i] = NULL;
    }

    return graphM;
}

void makeEdge(struct Graph* graphM, int snode, int dnode, int weight) {
    struct Node* new = create(dnode, weight);
    new->next = graphM->listOfNodes[snode];
    graphM->listOfNodes[snode] = new;

    new = create(snode, weight);
    new->next = graphM->listOfNodes[dnode];
    graphM->listOfNodes[dnode] = new;
}

void removeEdge(struct Graph* graph, int snode, int dnode) {
    struct Node* current = graph->listOfNodes[snode];
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->vertex == dnode) {
            if (prev == NULL) {
                graph->listOfNodes[snode] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void findMinEdge(struct Graph* graph, int* src, int* dest, int* weight) {
    int numVertices = graph->n;
    *src = -1;
    *dest = -1;
    *weight = INT_MAX;

    for (int u = 0; u < numVertices; u++) {
        struct Node* temp = graph->listOfNodes[u];
        while (temp != NULL) {
            if (temp->weight < *weight) {
                *src = u;
                *dest = temp->vertex;
                *weight = temp->weight;
            }
            temp = temp->next;
        }
    }
}

int find_parent(int i, int parent[]) {
    while (parent[i] != -1) {
        i = parent[i];
    }
    return i;
}

int KruskalsList(struct Graph *graph, int parent[]) {
    int weight = 0, min, i, j, ne=0, a, b;

    while (ne < n-1) {
        min = INT_MAX;

        findMinEdge(graph, &a, &b, &min);

        if (find_parent(a, parent) != find_parent(b, parent)) {
            parent[b] = a;

            printf("\nPath from %d to %d: %d\n", a, b, min);

            weight += min;
            ne++;
        }

        removeEdge(graph, a, b);
    } 

    return weight;
}

int KruskalsGraph(int g[n][n], int parent[]) {
    int a, b, weight = 0, min=INT_MAX, i, j, ne=0;

    while (ne < n-1) {
        min = INT_MAX;

        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                if (g[i][j] < min) {
                    min = g[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        
        if (find_parent(a, parent) != find_parent(b, parent)) {
            parent[b] = a;

            printf("\nPath from %d to %d: %d\n", a, b, min);
            weight += min;
            ne++;

        }
        g[a][b] = g[b][a] = INT_MAX;
    }
    return weight;
}

int main() {
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    int parent[n];

    // Initialize graph and parent
    for (int i=0; i<n; i++) {
        parent[i] = -1;
    }
    
    int graphM[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            graphM[i][j] = INT_MAX;
        }
    }

    getchar();
    struct Graph* graphL = makeGraph(n);

    // Loop for entering connection between vertices
    int exit=0;
    while (!exit) {
        printf("Enter an edge? (y/n): \n");
        char ans;
        scanf("%c", &ans);

        switch (ans) {
            case 'y': 
                printf("\nEnter the vertices (only 2): ");
                int v1, v2;
                scanf("%d %d", &v1, &v2);

                printf("\nEnter the weight: ");
                int w;
                scanf("%d", &w);

                graphM[v1][v2] = w;
                graphM[v2][v1] = w;

                makeEdge(graphL, v1, v2, w);

                getchar();
                break;

            case 'n':
                exit=1;
                break;

            default:
                printf("\nPlease enter an acceptable answer.\n");
                break;
        }
    }
    
    printf("\nKruskals Algorithm according to adjacency matrix:\n");

    // Weight calculated for matrix
    int weight = KruskalsGraph(graphM, parent);
    printf("\nWeight is %d", weight);

    for (int i=0; i<n; i++) {
        parent[i] = -1;
    }

    printf("\nKruskals Algorithm according to adjacency list:\n");
    
    // Weight calculated for list
    weight = KruskalsList(graphL, parent);
    printf("\nWeight is %d", weight);

    return 0;
}