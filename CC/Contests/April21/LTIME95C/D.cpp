#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e9 + 7;

void solve()
{
        int n, sum(0); cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            sum = (sum + arr[i] + N) % N;
        }
        int q; cin>>q;
        while(q--)
        {
            int a; cin>>a;
            sum = (sum*2)%N;
            cout<<sum<<endl;
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
