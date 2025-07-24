//   Fibonacci Series

#include<stdio.h>
int main()
{
  int num,f0 = 0, f1 = 1, f2;;
  scanf("%d",&num);
  printf("\n%d %d",f0,f1);
  for ( int i = 3; i <= num; i++)
  {
    f2 = f0+f1;
    printf(" %d",f2);
    f0 = f1;
    f1 = f2;   
  }
 return 0;
}