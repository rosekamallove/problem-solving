#include<iostream>
using namespace std;

int arrSum(int arr[], int n){
    int sm(0);
    for(int i=0; i<n; i++){
        sm += arr[i];
    }
    return sm;
}

bool allEqual(int arr[], int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] != arr[i+1])
            return 0;
    }
    return 1;
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    while(!allEqual(arr,n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i] > arr[j])
                    arr[i] = arr[i] - arr[j];
            }
        }
    }

    cout<<arrSum(arr,n)<<endl;
}

