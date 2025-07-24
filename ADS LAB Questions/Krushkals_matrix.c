#include <stdio.h>
#include <stdlib.h>
int inf = 999;
int parent[100];

int find_parent(int i)
{
    while(parent[i]!=i)
        i = parent[i];
    return i;
}
void change_parent(int i,int j)
{
    int x,r;
    x=find_parent(i);
    r=find_parent(j);
    parent[x]=r;
}
void Kruskals(int A[100][100],int n)
{
  int min=inf,a,b,i,j,cost=0,ne=0;
  for(i=0;i<n;i++)
    parent[i]=i;
  while(ne < n-1)
  {
      min=inf;
      for(i=0;i<n;i++)
      {
          for(j=0;j<n;j++)
          {
              int k = find_parent(i);
              if(k != find_parent(j) && A[i][j] < min)
              {
                  min=A[i][j];
                  a=i;
                  b=j;
              }
          }
      }
      change_parent(a,b);
      A[a][b]=A[b][a]=inf;
      cost+=min;
      ne++;
  }
  printf("The cost of the MST is:%d",cost);
}
int main()
{
    int E, V, j, e,v, A[100][100], weight,decision=1;
    printf("Enter the no. of vertices(consider 0):");
    scanf("%d", &V);
    for (int i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            A[i][j] = inf;
        }
    }
    do
    {
        printf("Enter the vertices of the edges:");
        scanf("%d %d",&e,&v);
        printf("Enter the weight:");
        scanf("%d",&weight);
        A[e][v]=A[v][e]=weight;
        printf("Do you want a edge:(Yes(1)) or (No(0)):");
        scanf("%d",&decision);
    } while (decision==1);
    Kruskals(A,V);
    return 0;
}
