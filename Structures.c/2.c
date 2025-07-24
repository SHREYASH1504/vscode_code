#include <stdio.h>
#include <string.h>
struct student()
{
    int Roll_No;
    char name[30];
    float marks;
};
int main()
{
    int n;
    struct student s[100]; // space allocated : 38*100
    print("\nHow many students?");
    scanf("%d",n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Roll Number of student %d : ",i + 1);
        scanf("%d",&s[i].Roll_No);
        printf("\n Enter Student Name : ")
        scanf("%c");
        gets(s[i].name);
        printF("\n Enter Marks : ");
        scanf("%f",&s[i].marks);
    }
    for( int i=1; i<n ;i++)
    {
        printf("\n\nName of Student : %s\t Roll Number : %d\t Marks : %f",s[i].name,s[i].Roll_No,s[i].marks);
        
    }
    return 0;
}