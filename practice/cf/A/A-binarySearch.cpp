#include<iostream>
#include<vector>
using namespace std;

bool bs(vector<int> v, int key) {
    int r = v.size(), l = 0;

    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(v[mid] == key) return 1;
        if(v[mid] > key) r = mid - 1;
        else l = mid + 1;
    }

    return 0;
}

int main(){
    int n, k; cin>>n>>k;

    vector<int> v(n), q(k);
    for(int i=0; i<n; i++) 
        cin>>v[i];
    for(int i=0; i<k; i++)
        cin>>q[i];

    for(int i=0; i<k; i++) {
        if(bs(v, q[i])) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}

