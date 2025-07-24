/*
Q3: print
E D C B A
E D C B
E D C
E D
E
*/

#include<stdio.h>
int main()
{
    for(int i='E'; i>='A'; i--)
    {
        for(int j=i; j>='A'; j--)
        {
            printf("%c ",j);
        }
        printf("\n");
    }
    return 0;
}
