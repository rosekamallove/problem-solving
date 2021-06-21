
// https://www.hackerrank.com/challenges/crush/problem

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x,y) cout << #x << ": " << x << #y << ": " << y << endl;
#define rep(i,n) for(int i(0); i<n; i++)
#define rip(i,n) for(int i(1); i<=n; i++)
#define rap(i,a,n) for(int i(a); i<=n; i++)

void solve()
{
    int T,n; cin>>n>>T;
    while(T--)
    {
        int a,b,k; cin>>a>>b>>k;
        int arr[n]; arr[0] = 0;

        rap(i,a,n-b+1)
            arr[i]+= k;

        int m(INT_MIN);

        rip(i,n)
            m = max(m, arr[i]);

        cout<<m<<endl;
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    solve();
}
