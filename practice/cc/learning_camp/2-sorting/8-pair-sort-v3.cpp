#include "bits/stdc++.h"
#include <utility>
using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    if(a.second == b.second) {
        return a.first > a.second;
    }
    return a.second > b.second;
}


signed main() {
    int n; cin>>n;
    vector<long long> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector< pair<long long, long long> > vp;

    for(int i=0; i<n; i++) {
        vp.push_back(make_pair(a[i], b[i]));
    }

    sort(vp.begin(), vp.end(), cmp);

    for(auto x : vp) {
        cout<<x.first <<' '<<x.second<<' ';
    }
    cout<<"\n";
}

