#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    int size;
    char *arr;
};

char StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

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

void push(struct stack*ptr, char value)
{
    if(IsFull(ptr))
    {
        printf("Stack Overflow...!");
    }
    else
    {
        ptr->top ++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        printf("Stack Underflow...!");
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top --;
    }
} 

int IsOperator(char value)
{
    if(value == '/' || value == '*' || value == '+' || value == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Precedence(char value)
{
    if(value == '/' || value == '*')
    {
        return 3;
    }
    else if(value == '+' || value == '-')
    {
        return 2;
    }
    else
        return 0;
}

char InfixToPostfix(char* Infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char *Postfix = (char*)malloc((strlen(Infix)+1)*sizeof(char));
    int i=0, j=0;

    while(Infix != '\0')
    {
        if(!IsOperator(Infix[i]))
        {
            Postfix[j] = Infix[i];
            i++;
            j++; 
        }
        else
        {
            if(Precedence(Infix[i]) > Precedence(StackTop(sp)))
            {
                push(sp, Infix[i]);
                i++;
            }
            else
            {
                Postfix[j] = pop(sp);
                j++;
            }
        }
    }

    while(!IsEmpty(sp))
    {
        Postfix[j] = pop(sp);
        j++;
    }
    Postfix[j] = '\0';
    return Postfix;
}

int main()
{
    char *Infix = "a-b";
    printf("Postfix : %s", InfixToPostfix(Infix));
}