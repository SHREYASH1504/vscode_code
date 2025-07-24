#include <stdio.h>
int main()
{
    int x[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p;
    p = x;
    /*
     printf("\n%p\n%p", x, p);
     printf("\n%d", x[7]);     //80
     printf("\n%d", *(x + 7)); //80
     printf("\n%d", *(7 + x)); //80
     printf("\n%d", 7[x]);     //80
     printf("\n--------------------------------------------------------------------------------");
     printf("\n%d", p[7]); // here  p pretends to be array x
     printf("\n%d", *(p + 7));
     printf("\n%d", *(7 + p));
     printf("\n%d", 7[p]);

     p[5] = 500;
     printf("\n%d", x[5]);
    */

    /*  
    p += 2;
    printf("\n p[4] : %d \n x[4] : %d", p[4], x[4]); //70  50
    */

    /*
    printf("\n%d", x[20]); //garbage value
    x[20] = 200;
    printf("\n%d", x[20]); //200
    printf("\n%d", p[20]); //200
   */
   
    printf("\n%d", x[-3]); //gives garbage value
    x[-3]= 200;
    printf("\n%d", x[-3]); //200
    printf("\n%d", p[-3]); //200
    return 0;
}
