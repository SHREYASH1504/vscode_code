/*
  swaping a value of x to y and vice versa.
  Q. What we want-A called function to change the values of local variables in calling function
*/
#include<stdio.h>
 void swap(int x, int y)
 {
  int temp;
  temp=y;
  y=x;
  x=temp;
  printf("\n %d  %d",x,y);
 }
 int main()
 {
 int x=10, y=20;
 //swap(x,y);
 printf("\n %d  %d",x,y);
 return 0; 
 }