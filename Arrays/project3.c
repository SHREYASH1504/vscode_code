#include<stdio.h>
#include<string.h>
 int main()
{
    char str[10]="Hello World";
    for(int i=0;i<10;i++)
    {
        if(str[i]=='W')
        {
            printf("W is present at %d",i);
        }
    }
 return 0;
}