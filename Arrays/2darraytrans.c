#include<stdio.h>
 
 int main()
 {
    int r,c,i=0,j=0;
    float x[10][10];
    float y[10][10];
    printf("Give Dimensions of a Matrix less than or equal to 10. \n");
    printf("Give no. of rows and columns for x matrix : \n");
    scanf("%d%d",&r,&c);

    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {
      printf(" Give Number : ",i+1,j+1);
      scanf("%f",&x[i][j]);
     }      
    }
    for(i=0;i<r;i++)
    {
     for(j=0;j<c;j++)
     {
      printf("\t%10.3f",x[i][j]);  
     }   
     printf("\n");
    }

    printf("Transpose of matrix x : \n");
    for(i=0;i<c;i++)
    {
     for(j=0;j<r;j++)
     {
       printf("\t%10.3f",y[i][j]=x[j][i]);
     }   
     printf("\n");
    }
 }

     
