#include<iostream>
using namespace std;

int binary(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return key;
        }

        if(mid < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }

    return -1;
}

int main()
{
    int even[6] = {1, 2, 3, 4, 5, 6};
    int odd[5] = {1, 2, 3, 4, 5};

    int index = binary(even, 6, 6);
    // binary(odd, 5, 5);

    cout << "Index of 6 is : " << index << endl;
}