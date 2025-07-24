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
}

void display (int dist[]) {
    printf("Vertex\tDistance from start\n");
    for (int i=0; i<n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int minvertex(int dist[], int visited[]) {
    int min=INT_MAX, v=0;

    for (int i=0; i<n; i++) {
        if (dist[i] < min && visited[i] == 0) {
            min = dist[i];
            v=i;
        }
    }
    
    return v;
}

int isPath(struct Graph *g, int u, int j) {
    struct Node *temp = g->listOfNodes[u];

    while (temp != NULL) {
        if (temp->vertex == j)
            return temp->weight;
        else    
            temp = temp->next;
    }

    return 0;
}

void DijkstraGraph(int graph[n][n], int start) {

    int dist[n], visited[n], u;

    for (int i=0; i<n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for (int i=0; i<n-1; i++) {
        u = minvertex(dist, visited);
        visited[u] = 1;

        for (int j=0; j<n; j++) {
            if (visited[j] != 1 && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    display(dist);
    
}

void DijkstraList (struct Graph *graph, int start) {

    int dist[n], visited[n], u;

    for (int i=0; i<n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    for (int i=0; i<n-1; i++) {
        u = minvertex(dist, visited);
        visited[u] = 1;

        for (int j=0; j<n; j++) {
            if (visited[j] != 1 && isPath(graph, u, j) && dist[u] != INT_MAX && dist[u] + isPath(graph, u, j) < dist[j]) {
                dist[j] = dist[u] + isPath(graph, u, j);
            }
        }
    }

    display(dist);
    
}

int main() {
    printf("Enter the number of nodes: \n");
    scanf("%d", &n);
    
    int graphM[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            graphM[i][j] = 0;
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
                printf("\nEnter the vertices (start and end): ");
                int v1, v2;
                scanf("%d %d", &v1, &v2);

                printf("\nEnter the weight: ");
                int w;
                scanf("%d", &w);

                graphM[v1][v2] = w;

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

    printf("\nEnter start node: ");
    int start;
    scanf("%d", &start);

    printf("\nDijkstras Algorithm according to adjacency matrix:\n");
    DijkstraGraph(graphM, start);
    

    printf("\nDijkstras Algorithm according to adjacency list:\n");
    DijkstraList(graphL, start);
   
    return 0;
}