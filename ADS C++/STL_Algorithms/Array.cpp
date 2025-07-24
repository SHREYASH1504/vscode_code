#include<iostream>
#include<array> // including stl array library
using namespace std;

int main()
{
    // basic static array
    int basic[3] = {1, 2, 3}; 

    // implementation of std array is carried out form fixed size static (basic) array 
    // therefore this is also static array
    array<int, 4> arr = {4, 5, 6, 7};

    int size = arr.size();   // array_name.size() used to calculate the size of the array

    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Element at index 2 : array_name.at(index)
    cout << "Element at index 2 : " << arr.at(2) << endl;  // O(1)

    // Checking if array is empty or not : array_name.empty() 
    cout << "Is Empty or not : " << arr.empty() << endl;  // O(1)

    cout << "First Element : " << arr.front() << endl;  // O(1)
    cout << "Last Element : " << arr.back() << endl;  // O(1)
}