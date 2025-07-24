#include<stdio.h>
#include<stdlib.h>

int i, n;

int minp(int dist[10], int visited[10])
 {
    int index, min = 99;
    for (i = 0; i < n; i++) 
    {
        if (dist[i] < min && visited[i] == 0)
        {
            min = dist[i];  
            index = i;
        }
    }
    return index;
}

    void display(int dist[10], int parent[10], int n)
    {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, dist[i]);
    }


}

void primMST(int G[10][10], int n)
 {
    int visited[10], dist[10], parent[10];
    int u, j, v;
    for (i = 0; i < n; i++)
     {
        visited[i] = 0;
        parent[i] = -1;
        dist[i] = 99;
    }
    printf("Enter Start Vertex:");
    scanf("%d", &v);
    dist[v] = 0;
    for (i = 0; i < n; i++)
     {
        u = minp(dist, visited);
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (G[u][j] < dist[j] && visited[j] == 0)
             {  
                dist[j] = G[u][j];
                parent[j] = u;
            }
        }
    }
    display(dist, parent, n);
}

int main() 
{
    int G[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    primMST(G, n);

    return 0;
}