#include<stdio.h>
#include<string.h>
 int main()
 {
   char name1[50];
   char name2[50];
   printf("Give Your Name: ");  
   gets(name1);
   int l=strlen(name1);
   printf("l=%d",l);
   puts(name1);
   strcpy(name1,name2);
   puts(name1);
   printf("name2=%s",name2);
   puts(name2);
   return 0;
 }

