#include <bits/stdc++.h>
using namespace std;

string twoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    bool possible(1);

    for(int i=0; i<A.size(); i++){
        if(!(A[i] + B[i] >= k)){
            possible = 0;
            break;
        }
    }
    return (possible ? "YES" : "NO");
}

int main() {
    int q; cin>>q;
    while(q--){
        int n, k;
        cin>>n>>k;
        vector<int> A(n), B(n);
        for(int &x : A) cin>>x;
        for(int &x : B) cin>>x;

        cout<<twoArrays(k, A, B);
    }
}
