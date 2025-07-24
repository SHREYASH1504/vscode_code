// Time Complexity = O(n^2)
// Space Complexity = O(1)

#include<iostream>
using namespace std;

int printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int BubbleSort(int arr[], int n)
{
    while(n>1)
    {
        bool swaped = false;
        for(int i=0; i<n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                swaped = true;
            }
            printArray(arr, 5);
        }
        if(swaped == false) break;
    }
    
}

int main()
{
    int arr[5] = {64, 25, 12, 22, 11};

    cout << "Given Array : ";
    printArray(arr, 5);
    BubbleSort(arr, 5);
    cout << "Sorted Array : ";
    printArray(arr, 5); 
}