#include<iostream>
#include<stack>
using namespace std;

class Stack {
    // properties
    public:
    int top ;
    int *arr;
    int size;

    // behaviour
    Stack(int size)
    {
        this -> size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int value)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = value;
        }
        else{
            cout << "stack overflow" << endl;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout << " stack underflow" << endl;
        }
        else 
        {
            top--;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int peek()
    {
        if(top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
};

int main()
{
    Stack s(5);

    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;   

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl; 

    cout << "Is Stack Empty? " << s.isEmpty() << endl;
    
}