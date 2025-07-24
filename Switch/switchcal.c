#include<stdio.h>

 int main()
 {
    int a,b,c;
    float d;
    printf("Select the correct choice as per your calculation : ");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        printf("You have selected Addition. Enter Two Values : ");
        scanf("%d%d",&b,&c);
        printf("Addition : %d",d=b+c);
        break;
        case 2:
        printf("You have selected Subtraction. Enter Two Values : ");
        scanf("%d%d",&b,&c);
        printf("Subtraction : %d",d=b-c);
        break;
        case 3:
        printf("You have selected Multiplication. Enter Two Values : ");
        scanf("%d%d",&b,&c);
        printf("Multiplication : %d",d=b*c);
        break;
        case 4:
        printf("You have selected Division. Enter Two Values : ");
        scanf("%d%d",&b,&c);
        printf("Division : %f",d=b/c);
        break;
        default:
        printf("\nSelect from the given choices. Thank You...");
        break;        
    }
    return 0;
 }