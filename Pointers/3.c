#include<stdio.h>
 /*int miain()
 {
    int a=10, b=20;
    swap(a,b);
    printf(a,b);
 }*/
 void swap(int *p1, int *p2)
 { // we are passing the address of a,b
  int temp;
  temp=*p1; //temp will store the value of address p1 
  *p1=*p2;  //value at address p1 will be replaced by p2
  *p2=temp; //value at address p1 will be replaced by temp
 }
 int main()
 {
    printf("%d  %d",p1,p2);
    return 0;
    
 }