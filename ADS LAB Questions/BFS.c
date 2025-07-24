#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int front;
    int back;
    int *arr;
};

int IsFull(struct queue*q)
{
    if(q->back == q->size-1)
        return 1;
    else
        return 0;
}

int IsEmpty(struct queue*q)
{
    if(q->front == q->back)
        return 1;
    else
        return 0;    
}

void Enqueue(struct queue*q, int value)
{
    if(IsFull(q))
    {
        printf("Queue Overflow...!");
    }
    else
    {
        q->back++;
        q->arr[q->back] = value;
    }

}

int Dequeue(struct queue*q)
{
    int a=-1;
    if(IsEmpty(q))
    {
        printf("Queue Underflow...!");
    }
    else
    {       
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main()
{
    struct queue q ;
    q.back = q.front = -1;
    q.size = 400;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // BFS Implementation
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = 
    {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0}
    };

    int node;
    int i = 1;
    printf("%d\t", i);
    visited[i] = 1;
    Enqueue(&q, i);  // for exploration
    while(!IsEmpty(&q))
    {
        node = Dequeue(&q);
        for(int j=0; j<7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0);
            {
                printf("%d", j);
                visited[j] = 1;
                Enqueue(&q, j);
            }
        }
    }
    return 0;
}
