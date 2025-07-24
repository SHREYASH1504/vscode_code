// TC = O(n^2)
// SC = O(1)

#include<iostream>
using namespace std;

int printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int InsertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int temp =arr[i];
        int j = i-1;
        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > temp)
            {
                // shift
                arr[j+1] = arr[j];
            }
            else
            {
                // stop
                break;
            }
        }
        
        printArray(arr, 5);
        arr[j+1] = temp;
    }
}

int main()
{
    int arr[5] = {64, 25, 12, 22, 11};

    cout << "Given Array : \n";
    printArray(arr, 5);
    InsertionSort(arr, 5);
    cout << "Sorted Array : ";
    printArray(arr, 5);
}