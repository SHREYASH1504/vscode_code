// Q2: WAP to create a function max_of_four(int a, int b, int c, int d)

#include<stdio.h>

int max_of_four(int a, int b, int c, int d)
{
    if(a>b)
    {
        if(a>c)
        {
            if(a>d)
            {
                return a;
            }
        }
    }
    if(b>c)
    {
        if(b>d)
        {
            return b;
        }
    }
    if(c>d)
    {
        return c;    
    }
    else{
        return d;
    }
}

int main()
 {
   int a,b,c,d;
   printf("Give four numbers : \n");
   scanf("%d%d%d%d",&a,&b,&c,&d);
   int max_of_four(int a, int b, int c, int d);
   printf("Greatest of four numbers is %d", max_of_four(a,b,c,d));
   return 0;
 }