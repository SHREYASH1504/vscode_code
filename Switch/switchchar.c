#include<stdio.h>

 int main()
 {
    char ch;
    printf("Enter Character : ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a':
        printf("Character is a\n");
        break;
        case 'b':
        printf("Character is b\n");
        break;
        case 'c':
        printf("Character is c\n");
        break;
        case 'd':
        printf("Character is d\n");
        break;
        default:
        printf("Enter correct value.");
    }
    return 0;
 }