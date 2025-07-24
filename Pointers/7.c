// Writing string functions using pointers and character array.
#include<stdio.h>
#include<string.h>
int mystrlen(char *s)
{
 /*int i=0;
 while(*s++ i++);
 return 1;*/
 char *p=s;
 while(*s++);
 return s-p-1;
}
/*void mystrcpy(char *d, char *s)
{
    int i=0;
    while (s[i != '\0'])
    {
        d[i]=s[i]; 
        i++;
    }
    d[i]=0;
    
}*/
int main()
{
    char name[20];
    printf("Give your name : ");
    gets(name);
    printf("\nYour name contains %d characters",mystrlen(name));
    return 0;
}