#include<iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int count = 0;
    for(int i = s+1; i<=e; i++)
    {
        if(arr[i] <= pivot)
            count++;
    }

    // positioning pivot element
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    // left part should be less than pivot & right part should be greater than pivot
    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
        return pivotIndex; 
    }
}

void quickSort(int arr[], int s, int e)
{
    //base case
    if(s >= e)
        return;

    int p = partition(arr, s, e);

    // left part sorting
    quickSort(arr, s, p-1);

    // right part sorting
    quickSort(arr, p+1, e);
}

int main() {
    int arr[7] = {7, 3, 9, 1, 6, 2, 0};
    int n = 7;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}