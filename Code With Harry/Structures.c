/*                                             ...STRUCTURES... 
    user defined datatype
    combine data of different type together 
    SYNTAX:
           struct employee                                   struct employee
           {                                                 {
            int id;                                           int id; 
            char name[50];                                    char name[50];  
            float marks;                                      float marks;    
           };                                                } e1, e2;    
           struct employee e1,e2;                                  
.                                                             int main()   
           int main()                                        {       
           {                                                  struct employee e1 = {12,44.21};
            struct employee e1;
            e1.id = 12;   // sturcture member operator(.)
            e1.marks = 44.21                                  return 0;     
            return 0;                                        }         
           }                                                 
*/

#include<stdio.h>

struct Student
{
   int id;
   int marks;
   char fav_char; 
};
                                            // global variable can be put here.
int main()
{
  struct Student shreyash, ashish, mrunal;  // local variable.
  shreyash.id = 1;
  ashish.id = 2;
  mrunal.id = 3;
  shreyash.marks = 100;
  ashish.marks = 99;
  mrunal.marks = 98;
  shreyash.fav_char = 'a';
  ashish.fav_char = 'b';
  mrunal.fav_char = 'c';

  printf("Shreyash id : %d\n", shreyash.id);
  printf("Shreyash got %d marks\n", shreyash.marks);
  printf("Shreyash's favourite character is %c", shreyash.fav_char);
  
  return 0;
}