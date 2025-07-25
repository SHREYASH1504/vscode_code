#include <iostream>
#include <queue>
using namespace std;

class heap {
public:
    int arr[100]; // Heap is implemented in the form of an array
    int size;

    heap() {
        arr[0] = -1; // Using 1-based indexing
        size = 0;
    }

    void insert(int val) {
        // TC = O(logn)
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteFromHeap() {
        // TC = O(logn)
        if (size == 0) {
            cout << "Empty Heap" << endl;
            return;
        }

        arr[1] = arr[size];
        size = size - 1;

        int i = 1;
        while (i <= size) {
            int leftIndex = i * 2;
            int rightIndex = i * 2 + 1;

            if (leftIndex <= size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if (rightIndex <= size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }

    void heapify(int i, int n, int arr[]) {
        // TC = O(logn)
        int largest = i;
        int left = i * 2;
        int right = i * 2 + 1;

        if (left <= n && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right <= n && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != i) {
            swap(arr[largest], arr[i]);
            heapify(largest, n, arr);
        }
    }

    void heapSort(int arr[], int n) {
        int size = n;

        while (size > 1) {
            // Step 1: Swap first and last elements
            swap(arr[size], arr[1]);
            size--;

            // Step 2: Restore the heap property
            heapify(1, size, arr);
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;

    // Insert elements into the heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    cout << "Heap after insertion: ";
    h.print();

    // Delete the root of the heap
    h.deleteFromHeap();
    cout << "Heap after deletion: ";
    h.print();

    // Create a heap from an array
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // 1-based indexing
    int n = 5;
    for (int i = n / 2; i > 0; i--)
        h.heapify(i, n, arr);

    cout << "Array after heapify (Heap Creation): ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using heap sort
    h.heapSort(arr, n);
    cout << "Array after heap sort: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    // PRORITY QUEUE
    // max heap
    priority_queue<int> q;
    q.push(1);
    q.push(5);
    q.push(9);
    q.push(4);

    cout << "Element at top : " << q.top() << endl;
    q.pop();
    cout << "Element at top : " << q.top() << endl;
    cout << "Size of Queue : " << q.size() << endl;

    //min heap
    priority_queue<int, vector<int>, greater<int>> p;
    p.push(1);
    p.push(5);
    p.push(9);
    p.push(4);

    cout << "Element at top : " << p.top() << endl;
    p.pop();
    cout << "Element at top : " << p.top() << endl;
    cout << "Size of Queue : " << p.size() << endl;

    return 0;
}
