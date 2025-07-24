#include<stdio.h>
#include<string.h>
 int main()
 {
    char name1[50];
    char name2[50];
    printf("Enter Name :");
    strcat(name1,name2);
    gets(name1);
    gets(name2);
    printf("name=%s",name1);
    printf("\nname=%s",name2);
    return 0;
 }