#include <stdio.h>
#include <stdlib.h>
struct student
{
int rollno;
char name[20];
float cpi;
};
void heapify(struct student a[], int n, int i)
{
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if (left < n && a[left].rollno > a[largest].rollno)
largest = left;
if (right < n && a[right].rollno > a[largest].rollno)
largest = right;
if (largest != i)
{
struct student temp = a[i];
a[i] = a[largest];
a[largest] = temp;
heapify(a, n, largest);
}
}
void heapsort(struct student a[], int n)
{
int i;
for (i = n / 2 - 1; i >= 0; i--)
{
heapify(a, n, i);
}
for (i = n - 1; i > 0; i--)
{
struct student temp = a[0];
a[0] = a[i];
a[i] = temp;
heapify(a, i, 0);
}
}
void print(struct student a[], int n)
{
for (int i = 0; i < n; i++)
{
printf("Student %d:\n", i + 1);
printf(" Name: %s\n", a[i].name);
printf(" Roll Number: %d\n", a[i].rollno);
printf(" CPI: %.2f\n", a[i].cpi);
}
}
int main()
{
struct student a[10];
int n;
printf("Enter the number of students: ");
scanf("%d", &n);
for (int i = 0; i < n; i++)
{
printf("Enter the student %d name: ", i + 1);
scanf("%s", a[i].name);
printf("Enter the student %d roll number: ", i + 1);
scanf("%d", &a[i].rollno);
printf("Enter the student %d CPI: ", i + 1);
scanf("%f", &a[i].cpi);
}
printf("\nBefore Sorting:\n");
print(a, n);
heapsort(a, n);
printf("\nAfter Sorting:\n");
print(a, n);
return 0;
}
