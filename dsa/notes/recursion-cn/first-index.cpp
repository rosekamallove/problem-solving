#include<iostream>
using namespace std;

int firstIndex(int n, int x, int arr[] ) {
    if(n == 0 ) return -1;
    if(arr[0] == x) return 0;

    int ans = firstIndex(n - 1, x, arr + 1);
    return ans == -1
           ? -1
           : ans + 1;
}

int lastIndex2(int n, int arr[], int x) {
    if(n <= 0) return -1;
    if(arr[n - 1] == x) return n - 1;
    return lastIndex2(n - 1, arr, x);
}

int lastIndex(int n, int x, int arr[]) {
    if(n == 0) return -1;
    int ans = lastIndex(n - 1, x,arr + 1);

    if(ans != -1) return ans + 1;
    if(arr[0] == x) return 0;
    else return -1;
}


int allIndexes(int input[], int size, int x, int output[]) {
    if(size == 0) return -1;
    return 0;
}

int allIndexesReversed(int input[], int size, int x, int output[]) {
    if(size <= 0) return 0;

    int smallAns = allIndexesReversed(input, size - 1, x, output);
    if(input[size - 1] == x) output[smallAns++] = size - 1;

    return smallAns;
}

int main() {
    int n, x;
    cin>>n>>x;
    int arr[n];

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<lastIndex2(n, arr, x)<<endl;
}

