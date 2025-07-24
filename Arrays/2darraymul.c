#include <stdio.h>
int main()
{
    int r1, c1, r2, c2, i = 0, j = 0;
    float x[10][10];
    float y[10][10];
    float z[10][10];
    printf("Give dimension of matrix less than or equal to 10. \n");
    printf("Give number of rows and coloumns of 1st matrix. \n");
    scanf("%d%d", &r1, &c1);
    r2 = c1;
    printf("Give number of columns of 2nd matrix :\n");
    scanf("%d", &c2);
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("\n Give Element [%d][%d] : ", i + 1, j + 1);
            scanf("%f", &x[i][j]);
        }
    }

    printf("\nGive number of rows and coloumns of 2nd matrix. \n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("\n give element [%d][%d] : ", i + 1, j + 1);
            scanf("%f", &y[i][j]);
        }
    }

    printf("\nMultiplication of two matrices : \n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            z[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                z[i][j] += x[i][k] * y[k][j];
            }
        }
    }

for (i = 0; i < r1; i++)
{
    for (j = 0; j < c2; j++)
    {
        printf("%10.3f", z[i][j]); // right align
    }
    printf("\n");
}
return 0;
}