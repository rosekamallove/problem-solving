#include<iostream>
#include<vector>
using namespace std;

void rightRotate(vector<int> &arr, int from, int to) {
    int temp = arr[to];
    for(int i=to; i<from; i++) {
        arr[i] = arr[i - 1];
    }
    arr[from] = temp;
}

void rearrangeArray(vector<int> arr, int n) {
    int wrongIndex = -1;

    for(int i=0; i<n; i++) {
        if(wrongIndex != -1) {
            if((arr[wrongIndex] >= 0 and arr[i] < 0) or (arr[wrongIndex] < 0 and arr[i] >= 0)) {
                rightRotate(arr, wrongIndex, i);
                if(i - wrongIndex  >= 2) {
                    wrongIndex += 2;
                } else {
                    wrongIndex = -1;
                }
            }
        } else if((arr[i] <0 and i%2 == 1) or (arr[i] >=0 and i%2 == 0)) {
            wrongIndex = i;
        }
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x : v) cin>>x;
    rearrangeArray(v, n);
    for(int &x : v) cout<<x<<' ';
    cout<<endl;
}

