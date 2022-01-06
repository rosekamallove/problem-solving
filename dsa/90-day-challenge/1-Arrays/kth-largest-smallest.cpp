#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;

    vector<int> v(n + 1);

    for(int &x : v) 
        cin>>x;

    sort(v.begin(), v.end());

    while(q--) {
        int x, k;
        cin>>x>>k;

        if(q == 0) {
            int ans = v[n - k];
            if(ans > x) {
                cout<<ans<<endl;
            } else {
                cout<<-1<<endl;
            }
        }

        if(q == 1) {
            int ans = v[k - 1];
            if(ans < x) {
                cout<<ans<<endl;
            } else {
                cout<<-1<<endl;
            }
        }
    }
}

