/* Q1: print 
A
A B 
A B C 
A B C D 
A B C D E
A B C D
A B C
A B 
A
*/

#include<stdio.h>
int main()
{
    int i,j;
    for (i='A'; i<='E'; i++)
    {
        for (j='A'; j<=i; j++)
        {
          printf("%c ", j);          
        }
        printf("\n");
    }

    for (j='A'; j>='D'; ++j)
    {
        for (i='A'; i>=i; ++i)
        {
          printf("%c ", i);          
        }
        printf("\n");
    }
    return 0;
}
