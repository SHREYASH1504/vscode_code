#include<stdio.h>
 int main()
 {
    FILE *fp;
    fp = fopen("lecture2.txt","wt");
    if (fp = NULL) 
    {
    printf("Unable to open file ");
    return 1;
    }
    printf("%s\t%s\t\t%s\n","Roll No.","Name","Marks");
    fprintf(fp,"%s\t%s\t\t%s\n","Roll No.","Name","Marks");
    printf("%d\t%s\t%f\n",10,"Milind Pathwardhan",93.7);
    fprintf(fp,"%d\t%s\t%f\n",10,"Milind Pathwardhan",93.7);
    printf("%d\t%s\t%f\n",23,"Shreyash Nikhare",98.2);
    fprintf(fp,"%d\t%s\t%f\n",23,"Shreyash Nikhare",98.2);
    fclose(fp);
    return 0;    
 }