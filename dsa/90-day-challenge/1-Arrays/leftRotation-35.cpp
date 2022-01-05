#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leftRotateRev(int d, vector<int> &arr){
    int k = arr.size() - d;
    k = k%arr.size();

    /*
     * p1 + p2      (Breaking the array into two parts)
     * p1` + p2`    (Reversing Individually)
     * p2`` + p1``  (Reversing Whole)
     * p2 + p1      (What we wanted)
     */

    reverse(arr.begin(), arr.end() - k);
    reverse(arr.end() - k, arr.end());
    reverse(arr.begin(), arr.end());

    return arr;
}

int main() {
    int n, d; cin>>n>>d;
    vector<int> v(n);
    for(int &x : v) cin>>x;
    vector<int> rotated = leftRotateRev(d, v);
    for(int &x : rotated) cout<<x<<' ';
    cout<<endl;
}
