#include<iostream>
using namespace std;

bool search(int num[], int n, int key)
{
    for( int i=0; i<n; i++)
    {
        if(num[i]==key)
        return true;
    }
    return false;
}

int main()
{
    int num[10] = {2, 33, 83, 47, 34, 27, 1, 0, 88, 100};
    cout << "Enter the element to search for : " ;
    int key ;
    cin >> key;
    bool found = search(num, 10, key);

    if(found)
    {
        cout << "Element is present" << endl;
    }
    else
    {
        cout << "Element is not present" << endl;
    }
    
}