#include<iostream>
#include<vector>
using namespace std;

void dnfSort(vector<int> &v) {
    int lo(0), mid(0), hi(v.size() - 1);
    while(mid <= hi) {
        switch(v[mid]) {
        case 0:
            swap(v[lo++], v[mid++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(v[mid++], v[hi--]);
            break;
        }
    }
}

void cntSort(vector<int> &v) {
    int one(0), two(0), zero(0);

    for(int &x : v) {
        if(x == 1) one++;
        if(x == 2) two++;
        if(x == 0) zero++;
    }
    v = {};
    while(zero--) v.push_back(0);
    while(one--)  v.push_back(1);
    while(two--)  v.push_back(2);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &x : arr) cin>>x;
    cntSort(arr);
    for(int &x : arr) cout<<x<<' ';
}

