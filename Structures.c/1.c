// Structures in C : 
#include<stdio.h>
#include<string.h>
struct student() //outside main
 {
   int Roll_No;
   char name[30];
   float marks;
 };
  int main()
  {
    struct student s1={46,'Shreyash',9.5}, s2, s3;
    s2 = s1;
    s3.Roll_No. = 30;
    strcpy(s3.name,'Milind');
    s3.marks = 99.23; 
    printf("\n %d\t%s\t%f",s1.Roll_No,s1.name,s1.marks);
    printf("\n %d\t%s\t%f",s2.Roll_No,s2.name,s2.marks);
    printf("\n %d\t%s\t%f",s3.Roll_No,s3.name,s3.marks);

    return 0;
  }