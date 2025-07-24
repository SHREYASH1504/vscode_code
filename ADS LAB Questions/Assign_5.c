#include<stdio.h>
#include<stdlib.h>
#define max 15

struct vertex {
    int data;
    struct vertex *next;
};

void insertl(int, int, struct vertex [], int);
void insertm(int n, int [n][n], int, int);

struct queue {
    int v;
    struct queue *next;
};
struct queue *front = NULL;
struct queue *rear = NULL;

void enqueue(int);
int notemptyqueue(void);
int dequeue(void);

void bfsl(struct vertex [], int);
void bfsm(int n, int [n][n]);

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
    // initialise all
    struct vertex graphl[v];
    for (int i = 0; i < v; i++)
    {
        graphl[i].data = i;
        graphl[i].next = NULL;
    }
    int exit;
    // we keep taking inputs till the user exits
    do {
        printf("Do you want to enter an edge (1: yes, 0: no): ");
        scanf("%d", &exit);
        if (exit)
        {
            int v1, v2;
            ret:
            printf("\nEnter the vertices of edge: ");
            scanf("%d%d", &v1, &v2);
            if ((v1 >= v)||(v2 >= v))
            {
                printf("\nError! number of nodes exceeded!");
                goto ret;
            }
            insertm(v, graphm, v1, v2);
            insertl(v1, v2, graphl, v);
        }
    } while (exit);
    bfsl(graphl, v);
    bfsm(v, graphm);
    return 0;
}

int notemptyqueue(void)
{
	return ((front != NULL)&&(rear != NULL));
}

void insertl(int vertex1, int vertex2, struct vertex graph[], int n)
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

void enqueue(int v)
{
	struct queue *temp = (struct queue *) malloc(sizeof(struct queue));
	temp->v = v;
	temp->next = NULL;
	if (notemptyqueue() == 0)
	{
		rear = temp;
		front = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

int dequeue(void)
{
    if (front != NULL)
    {
        int temp = front->v;
        struct queue *t = front;
        front = front->next;
        if (t == rear)
        {
            rear = NULL;
        }
        free(t);
        return temp;
    }
}

void bfsl(struct vertex graph[], int n)
{

    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[2] = 0;
    int v;
    back:
    printf("\nEnter start node: ");
    scanf("%d", &v);
    if (v > n)
    {
        printf("\nError! wrong node entered!");
        goto back;
    }
    visited[v] = 1;
    enqueue(v);
    while (notemptyqueue())
    {
        v = dequeue();
        printf("%d ", v);
        struct vertex temp = graph[v];
        struct vertex *p = temp.next;
        while (p != NULL)
        {
            if (visited[p->data] == 0)
            {
                enqueue(p->data);
                visited[p->data] = 1;
            }
            p = p->next;
        }
    }
}

void bfsm(int n, int graph[n][n])
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[2] = 0;
    int v;
    back:
    printf("\nEnter start node: ");
    scanf("%d", &v);
    if (v > n)
    {
        printf("\nError! wrong node entered!");
        goto back;
    }
    visited[v] = 1;
    enqueue(v);
    while (notemptyqueue())
    {
        v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++)
        {
            if ((graph[v][i] == 1)&&(visited[i] == 0))
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}