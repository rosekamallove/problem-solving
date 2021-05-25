#include<iostream>
using namespace std;

int findElement(int arr[], int l, int r, int x){
    if(r >= l){
        int mid = l + (r-l)/2;

        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            return
                findElement(arr, l, mid-1, x);
        return
            findElement(arr, mid+1, r, x);
    }
    return -1;
}

int findElementIterative(int arr[], int w, int n, int k){
    int low(0), high(n);

    while(low<=high){
        int mid(low + (high - low)/2);

        if(arr[mid] == k)
            return mid;
        else if(arr[mid] < k)
            low = mid + 1;
        else if(arr[mid] > k)
            high = mid - 1;
    }
    return -1;
}

int main(){
    int n, k; cin>>n>>k;
    int arr[n];
    for(int i=0; i <n; i++)
        cin>>arr[i];
    cout<<findElementIterative(arr, 0, n, k)<<endl;
}
