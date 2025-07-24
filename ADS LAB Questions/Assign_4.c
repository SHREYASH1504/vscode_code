#include <stdio.h>
#include <stdlib.h>
#define max 15

struct vertex
{
    int data;
    struct vertex *next;
};
struct stack
{
    int v;
    struct stack *next;
};
struct stack *top = NULL;
void insertl(int, int, struct vertex[]);
void insertm(int n, int[n][n], int, int);
void push(int);
int pop(void);
int notemptystack(void);
void dfsl(struct vertex[], int);
void dfsm(int n, int[n][n]);
struct vertex graphl[v];
for (int i = 0; i < v; i++)
{
    graphl[i].data = i;
    graphl[i].next = NULL;
}
int exit;
// we keep taking inputs till the user exits
do
{
    printf("Do you want to enter an edge (1: yes, 0: no): ");
    scanf("%d", &exit);
    if (exit)
    {
        int v1, v2;
        printf("\nEnter the vertices of edge: ");
        scanf("%d%d", &v1, &v2);
        insertm(v, graphm, v1, v2);
        insertl(v1, v2, graphl);
    }
} while (exit);
printf("\nperforming DFS using adjacency list: \n");
dfsl(graphl, v);
printf("\nperforming DFS using adjacency matrix: \n");
dfsm(v, graphm);
printf("\n");
return 0;
}
void insertl(int vertex1, int vertex2, struct vertex graph[])
{
    struct vertex *temp;
    temp = (struct vertex *)malloc(sizeof(struct vertex));
    temp->data = vertex2;
    temp->next = graph[vertex1].next;
    graph[vertex1].next = temp;
    temp = (struct vertex *)malloc(sizeof(struct vertex));
    temp->data = vertex1;
    temp->next = graph[vertex2].next;
    graph[vertex2].next = temp;
    return;
}
void insertm(int n, int graph[n][n], int vertex1, int vertex2)
{
    graph[vertex1][vertex2] = 1;
    graph[vertex2][vertex1] = 1;
    return;
}
void push(int n)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->v = n;
    temp->next = top;
    top = temp;
    return;
}
int pop(void)
{
    struct stack *temp = top;
    top = top->next;
    int n = temp->v;
    free(temp);
    return n;
}
int notemptystack(void)
{
    return (top != NULL);
}
void dfsl(struct vertex graph[], int n)
{
    int visited[n];
    struct vertex *p;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int v;
    printf("\nEnter start vertex: ");
    scanf("%d", &v);
    push(v);
    visited[v] = 1;
    printf("%d-", v);
    do
    {
        p = graph[v].next;
        while (p != NULL)
        {
            if (visited[p->data] == 0)
            {
                printf("%d-", p->data);
                push(p->data);
                visited[p->data] = 1;
                v = p->data;
                break;
            }
            else
                p = p->next;
        }
        if (p == NULL)
        {
            pop();
            if (notemptystack())
                v = top->v;
        }
    } while (notemptystack());
}
void dfsm(int n, int graph[n][n])
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int v;
    printf("\nEnter start vertex: ");
    scanf("%d", &v);
    push(v);
    visited[v] = 1;
    printf("%d-", v);
    do
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if ((graph[v][i]) && (visited[i] == 0))
            {
                printf("%d-", i);
                push(i);
                visited[i] = 1;
                v = i;
                break;
            }
        }
        if (i == n)
        {
            pop();
            if (notemptystack())
                v = top->v;
        }
    } while (notemptystack());
}
int main()
{
    // number of nodes
    int v;
    printf("Enter number of nodes (max: 15): ");
    scanf("%d", &v);
    if (v > max)
    {
        printf("Number of maximum nodes exceeded !");
        v = max;
    }
    // graph noted as matrix and list
    int graphm[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = i; j < v; j++)
        {
            graphm[i][j] = 0;
            graphm[j][i] = 0;
        }
    }