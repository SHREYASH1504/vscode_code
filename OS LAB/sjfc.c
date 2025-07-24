#include<stdio.h>
#include<stdlib.h>

int main()
{
    int at[10], bt[10], tat[10], wt[10], i, j, n, temp, st[10], ft[10];
    float atat, awt;
    char p[10], t[10];

    printf("Enter the Number of Processes : ");
    scanf("%d", &n);
    printf("Enter %d Processes Numbers : ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter %d Arrival Time : ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter the Burst Time : ", n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &bt[i]);
    }
}
