#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;

};
int isEmpty(struct stack* ptr){
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1)
        return 1;
    else
        return 0;
}
void Push(struct stack* ptr,int value){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
    ptr->top++;
    ptr->arr[ptr->top]= value;
    }

}
int Pop(struct stack* ptr){
    int val;
    if(isEmpty(ptr)){
        printf("Stack Underflow");
    }
    else{
    val = ptr->arr[ptr->top];
    ptr->top--;
    }
    return val;

}



int main(){
    struct stack*s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    // DFS IMPLEMENTATION

    int visited[7]= {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,0,1,0},
        {0,0,0,0,0,1,0},
    };

    int v=0;
    Push(s,v);
    visited[v] = 1;
    printf("%d",v);
    
    do
    {
        for(int j =0; j<7 ; j++)
        {
            if(a[v][j] == 1 && visited[j] == 0)
            {
                Push(s,j);
                printf("%d",j);
                visited[j] = 1;
                v = j;
                break;
            } 
        }
    }while(!isEmpty(s));

    return 0;
}
