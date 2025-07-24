#include<iostream>
using namespace std;

int main() {
    int i=1, j, n;
    cin >> n ;

    while(i<=n) {
        j=1;
        while(j<=n) {
            cout << j <<" ";
            j=j+1;
        }
        cout << endl;
        i=i+1;
    }
}