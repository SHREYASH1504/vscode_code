/*
 Pointer is a variable that storess the address of other variable.
 '&' operator is to be read as 'Address of'.
 pointer to integer: a variable that stoires address of pointer to integer.(and like vise)
 int x,y,z,*p,w,*q;  (x,y,z,w are integer and p,q are pointer to integer)
 all are holding garbage address till it is initialized
 p =&x; (now p will store adderss of x)
 *: value of address
 y=*p; (go to the address of p then go to its value address(x=20) and pick up the value and store it in y(y=20))
 *p=*p+10; (x=20) 
*/
#include<stdio.h>
int main()
{
    int x, *p, **q,y= 50;
    x=20;
    p=&x;
    q=&p;
    *p=*p+20;
    printf("\n%d\n%d\n%d",x,*p,**q); //40 40 40
    p=&y;
    printf("\n\n%d\n%d\n%d",x,*p,**q); //40 50 50 
    return 0;
}
