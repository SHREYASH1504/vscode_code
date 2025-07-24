#include<stdio.h>

 int main()
 {
    char names[10][30]; // 2d array having 10 names each of max sixe 29
    int i,n;
    printf("How many names : ");
    scanf("%d",&n);
    fflush(stdin);
    for( i=0;i<n;i++)
    {
        printf("Give name %d : ",i+1);
        gets(names[i]);        
    }
     for(int end=n-2;end>0;end--)
     {
       for(i=0;i<=end;i++)
       {
        
       }
     }

    for( i=0;i<n;i++)
    {
        puts(names[i]);
    }
    return 0;   
 }