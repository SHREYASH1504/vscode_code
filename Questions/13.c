// Matrix Addition, Subtraction, Transpose and Multipliation

#include<stdio.h>
int main()
{
    int r,c,i=0,j=0;
    float x[10][10];
    float y[10][10];
    float z[10][10];
    printf(" Give Dimentions of Matrix. ");
    printf("\n Give Numbers of Rows and Columns of x matrix : \n");
    scanf("%d\n%d",&r,&c);
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\n Give Numbers (%d,%d) :",i+1,j+1);
            scanf("%f",&x[i][j]);
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\t%10.3f",x[i][j]);
        }
        printf("\n");
    }

    printf("\n Give Numbers of Rows and Columns of y matrix : ");
    scanf("%d\n%d",&r,&c);
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\n Give Numbers (%d,%d) :",i+1,j+1);
            scanf("%f",&y[i][j]);
        }
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\t%10.3f",y[i][j]);
        }
        printf("\n");
    }

    printf("\n Addition of Matrix x and y : \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\t%10.3f",z[i][j]=x[i][j]+y[i][j]);
        }
        printf("\n");
    } 

    printf("\n Subtraction of Matrix x and y : \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\t%10.3f",z[i][j]=x[i][j]-y[i][j]);
        }
        printf("\n");
    }  

    printf("\n Transpose of matrix z : \n");
    for(i=0; i<c; i++)
    {
        for(j=0; j<r; j++)
        {
            printf("\t%10.3f",z[i][j]=z[j][i]);
        }
        printf("\n");
    }
    return 0;
}