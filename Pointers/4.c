/*
  Operation on Pointers:
  1. Assignment operation: You can assign one pointer to another pointer of same type.
     int x, *p1, *p2;
     x=10;
     y=20;
     p1=&x;
     p2=p1;
  2. You can add or subtract an integer to a pointer. The result is a pointer.
     int x, *p1, *p2;
     x=10;
     y=20;
     p1=&x;
     p1 = p1 + 1; // 1000 will change to 1004 size of p1 will be 4 staring from 1004).
  3. Subtraction of two pointer of same type.
     p1 = &x;
     p2 = &y;
     int i = p2 - p1; // address of i will be @250 (p2-p1=1000/4=250)   
  4. All other operation can be applied in pointers like arithmentix equations like (<,>,<=,>=!=,==)
  5. NULL Pointer has a value 0
     int *p1 = NULL;
     To avoid bugs due to garbage address in pointers, tehy are declared NULL. They can't be used or manipulated.
  6. logical operation are also not allowed rarely used.
  7. Bitwise operations are also not used.
*/

/*
  Pointers and Arrays:
  int x[100]; those 400 bit location have to be in continious memory location.
  array name is just holding the initial address of the bunch only.
  array name is pointer to integer
*/
/*
  x[7] ---> *(x+7) if starting loction of x is 1000 the x[7] means location of x + 7 and its value
*/

#include<stdio.h>
int main()
{
    int x[100];
    for( int i=0;i<100;i++)
    {
    printf("\n %d",&x[i]);
    }    
    return 0;
}