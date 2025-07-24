#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int IsEmpty(struct stack*ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct stack*ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack*ptr, int value)
{
    if(ptr->top == ptr->size-1)
    {
        printf("Stack Overflow...!");
    }
    else
    {
        ptr->top ++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack *ptr)
{
    int value;
    if(ptr->top == -1)
    {
        printf("Stack Underflow...!");
    }
    else
    {
        value = ptr->arr[ptr->top];
        ptr->top --;
    }
    return value;
} 

int factorial(int n)
{
    struct stack *p = (struct stack*)malloc(sizeof(struct stack));
    p->top = -1;
    p->size = 100;
    p->arr = (int *)malloc(p->size*sizeof(int));
    int result = 1;

    for(int i=1; i<=n; i++)
    {
        push(p, i);
    }

    while(!IsEmpty(p))
    {
        result = result * pop(p);
    }
    free(p->arr);
    free(p);
    return result;
}

void Fibonacci(int n)
{
    struct stack *fibStack = (struct stack*)malloc(sizeof(struct stack));
    fibStack->top = -1;
    fibStack->size = n + 1;
    fibStack->arr = (int *)malloc(fibStack->size * sizeof(int));

    push(fibStack, 0); // Push the first Fibonacci number
    push(fibStack, 1); // Push the second Fibonacci number

    printf("Fibonacci Series up to %d terms:\n", n);

    for (int i = 2; i <= n; i++) {
        int num1 = pop(fibStack);
        int num2 = pop(fibStack);

        int nextFib = num1 + num2;

        printf("%d ", nextFib);

        push(fibStack, num2); // Push the previous Fibonacci number
        push(fibStack, num1); // Push the current Fibonacci number
        push(fibStack, nextFib); // Push the next Fibonacci number
    }

    free(fibStack->arr);
    free(fibStack);
}

int main()
{
    int n;
    printf("Calculate the factorial of : ");
    scanf("%d", &n);
    printf("The factorial of %d is : %d", n, factorial(n));

    printf("\nEnter the Number : ");
    scanf("%d", &n);
    Fibonacci(n);
    return 0;
}