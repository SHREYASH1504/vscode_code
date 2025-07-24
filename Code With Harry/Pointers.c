/*                                                ...POINTERS...
   variable which stores address of another variable.
   can be type int, char, array, function, or any other pointers.
   declared using '*' 
   the address operator '&' returns the address of variable
   '*' is the dereference operator (indirectional operator) used to get the value at a given address.

   NULL POINTER :
   a pointer that has not assigned any value
   does not point to any object or function
   use it to initialise a pointer variable isnt assigned any valid memory address yet
   used for dynamic memory allocation
   return multiple values from a function

   ARRAYS AND POINTERS ARITHMETICS :
   arr[i] == *(arr + i)
   if arr is a pointer to arr[0] then arr + i is a pointer to arr[i]


*/

// CODE 1 :
/*
#include<stdio.h>

int main()
{
    int a =99;
    int *ptra = &a;
    int *ptr2 = NULL;

    printf("The address of a is %p\n",&ptra);    // ways to print address
    printf("The address of a is %p\n",&a);
    printf("The address of a is %p\n",ptra);

    printf("The  value of  a is %p\n",*ptra);    // ways to print value
    printf("The  value of  a is %p\n",a);

    printf("The address of some garbage is %p\n",ptr2);   // NULL pointer value = 00000000

    return 0;
}
*/

// CODE 2 :
/*

#include<stdio.h>

int main()
{
    int a =33;
    int *ptra = &a;
    printf("%d\n",ptra);// gives address of a
    printf("%d\n",ptra+1);// adds the size of datatype of variable used to its address and returns (as int takes 4 bits)
    printf("%d\n",ptra++);
    printf("%d\n",ptra-4);
    return 0;
}
*/

// CODE 3 :
#include<stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    printf("Value at position 3 of the array is %d\n",arr[2]);
    printf("The address of first element of the array is %d \n", &arr[0]);
    printf("The address of first element of the array is %d \n", arr);
    printf("The address of second element of the array is %d \n", &arr[1]);
    printf("The address of second element of the array is %d \n",arr + 1);
    printf("The address of third element of the array is %d \n", &arr[2]);

    printf("Value at position 3 of the array is %d\n",arr[2]);
    printf("The address of first element of the array is %d \n", &arr[0]);
    printf("The address of first element of the array is %d \n", arr);
    printf("The address of second element of the array is %d \n", &arr[1]);
    printf("The address of second element of the array is %d \n",arr + 1);
    printf("The address of third element of the array is %d \n", &arr[2]);

    return 0;
}
