// to check weather a no is prime or not.

#include<stdio.h>

int prime(int n)
{
    int i,c=0;
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            c=c+1;
        }
    }
    if(c==2)
    {
        printf("%d is a prime number",n);
    }
    else
    {
        printf("%d is not a prime number",n);
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter a Number : ");
    scanf("%d",&n);
    prime(n);
}