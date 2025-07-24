#include<stdio.h>
#include<string.h>
int main() 
{ 
 char a[50],b[50]; 
 int i=0,j=0,x,y,c=0,d=0,e=0,dir,n; 
 printf("Enter Main String : "); 
 gets(a); 
 printf("Enter Substring : "); 
 gets(b); 
 x=strlen(a); 
 y=strlen(b); 
 printf("Enter Occurence : "); 
 scanf("%d",&n); 
 printf("Enter Direction(0:Left to Right 1:Right to Left) : "); 
 scanf("%d",&dir); 
 for(j=j;j<x;j++) 
 { 
  if(a[j]==b[i]) 
  { 
   if(d==n-1) 
   { 
    if(i==0) 
    { 
     e=j; 
    } 
   }  
   if(i==y-1) 
   { 
    c=1; 
    d++; 
   } 
    i++; 
    if(i==y) 
    { 
     i=0; 
    } 
    if(d==n) 
    { 
      break; 
    } 
   }
  } 
  if(c==1) 
  { 
  if(d==n) 
  { 
   if(dir==0) 
   { 
    printf("position is %d",e); 
   } 
   else
   { 
    printf("positon is %d",x-y-e); 
   } 
  } 
  else
  { 
   printf("-1."); 
  } 
  } 
 else
  { 
   printf("-1."); 
  } 
 return 0; 
}