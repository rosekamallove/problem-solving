#include<iostream>
using namespace std;

bool isPresent(int input[], int size, int x) {
    if(size == 0) return false;
    if(input[0] == x) return true;
    return isPresent(input + 1, size - 1, x);
}

int main() {
    int arr[3] = {9,8,10};
    cout<<isPresent(arr, 3, 7)<<endl;
}
