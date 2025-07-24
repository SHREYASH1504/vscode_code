#include<stdio.h>

 int main()
 {
    int a=1000,b=2000;
    int x[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int c =3000, d=4000;
    printf("\nAddress of a is %d",&a);
    printf("\nAddress of b is %d",&b);
    printf("\nAddress of c is %d",&c);
    printf("\nAddress of d is %d",&d); 
    printf("\nAddress of x is %d",&x); 

    x[10]=398, x[11]=498; 
    printf("\n %d",&a);
    printf("\n %d",&b);

    return 0;
 }