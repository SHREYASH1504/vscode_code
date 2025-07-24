#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr;  // currently the size of the array is 0

    cout << "Capacity : " << arr.capacity() << endl;  // how much size is assigned to the array
    arr.push_back(1);  // adds element to the array
    cout << "Capacity : " << arr.capacity() << endl;
    arr.push_back(2);
    cout << "Capacity : " << arr.capacity() << endl;
    arr.push_back(3);
    cout << "Capacity : " << arr.capacity() << endl;

    cout << "Size : " << arr.size() << endl;  // how many elements are present in the array

    cout << "First Element : " << arr.front() << endl;
    cout << "Last Element : " << arr.back() << endl;

    cout << "Element at 2nd Index : " << arr.at(2) << endl;

    // printing array before popping
    cout << "Before pop : ";
    for(int i:arr)
        cout << i << " ";
    cout << endl;    
    
    // printing array after popping 
    cout << "After pop : ";
    arr.pop_back();
    for(int i:arr)
        cout << i << " ";
    cout << endl;

    cout << "Capacity : " << arr.capacity() << endl;  // capacity remains same after popping the element
    cout << "Size : " << arr.size() << endl;  // size reduces after changing the element

    // creating an array of some size 
    // and intializing all the elements with 1
    // array_name(array_size, initialising_element)
    vector<int> a(5, 1); 
    cout << "Array a : ";
    for(int i:a)
        cout << i << " ";
    cout << endl;

    // copying the array 'a' in another array 'copy'
    vector<int> copy(a);
    cout << "Array last : ";
    for(int i:a)
        cout << i << " ";
    cout << endl;

}