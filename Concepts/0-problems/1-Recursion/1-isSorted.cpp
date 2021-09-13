#include<iostream>
using namespace std;

bool isSorted(int size, int arr[]) {
    if(size == 1 or size == 0) {
        return true;
    }
    if(arr[0] > arr[1]) {
        return false;
    }
    return isSorted(--size, arr + 1);
}

int main() {
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5};
    cout<<isSorted(n, arr);
}

