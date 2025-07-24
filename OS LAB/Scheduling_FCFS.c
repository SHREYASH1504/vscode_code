#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp = 0, n;
    float atat = 0, awt = 0;

    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter %d processes : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter %d Arrival Time : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter %d Burst Time : ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    // Sorting according to arrival time
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < (n - i); j++)
        {
            if (at[j] > at[j + 1])
            {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;

                temp = at[j + 1];
                at[j + 1] = at[j];
                at[j] = temp;

                temp = bt[j + 1];
                bt[j + 1] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // calculating 1st ct
    ct[0] = at[0] + bt[0];

    // calculating 2nd to nth ct
    for (i = 1; i < n; i++)
    {
        temp = 0;
        if (at[i] > ct[i - 1])
        {
            temp = at[i] - ct[i - 1];
        }
        ct[i] = ct[i - 1] + bt[i] + temp;
    }

    for(i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }
    atat = atat/n;
    awt = awt/n;
    printf("\n p\t AT\t BT\t CT\t TAT\t WT");
    for(i=0; i<n; i++)
    {
        printf("\nP%d\t %d\t %d\t %d\t %d\t %d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Tuen Around Time is %f", atat);
    printf("\nAverage Waiting Time is %f", awt);

    return 0;
}