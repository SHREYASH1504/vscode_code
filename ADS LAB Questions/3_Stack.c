#include<stdio.h>

struct stack
{
    int top;
    int size;
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

void IsFull(struct stack*ptr)
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

void pop(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        printf("Stack Underflow...!");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top --;
    }
} 

void display(struct stack *ptr)
{
    if(IsEmpty(ptr))
    {
        printf("Stack Is Empty...!");
    }
    else
    {
        while(ptr->top != -1)
        {
            printf("%d\n", ptr->arr[ptr->top]);
        }
    }
}

int main()
{
    
    return 0;
}