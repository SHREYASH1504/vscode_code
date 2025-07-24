#include<stdio.h>

 int main()
 {
    char ch;
    /*Grade A= 90+ Percentage
      Grade B= 80+ Percentage
      Grade C= 70+ Percentage
      Grade D= 60+ Percentage
      Grade E= 50+ Percentage*/
    printf("Enter Grades : ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'A':
        printf("Congratulation... You Have Scored 90+ Percentage");
        break;
        case 'B':
        printf("Congratulation... You Have Scored 80+ Percentage");
        break;
        case 'C':
        printf("Congratulation... You Have Scored 70+ Percentage");
        break;
        case 'D':
        printf("Congratulation... You Have Scored 60+ Percentage");
        break;
        case 'E':
        printf("Congratulation... You Have Scored 50+ Percentage");
        break;
        default:
        printf("Chutiye padhai kr le. Fail ho gya tu laude.");
        break;
        
    }  
      
 }