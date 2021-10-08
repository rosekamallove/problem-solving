#include<iostream>
using namespace std;

int arrSum(int input[], int n) {
    if(n == 0) {
        return 0;
    }
    return input[n - 1] + arrSum(input, n-1);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<arrSum(arr, n);
}

