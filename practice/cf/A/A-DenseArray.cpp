#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x)        cout << #x << ": " << x << endl
#define tdeb(x,y)     cout << #x << ": " << x << #y << ": " << y << endl
#define rep(i,n)      for (int i(0); i<n ;  i++)
#define rip(i,n)      for (int i(1); i<=n;  i++)
#define rap(i,a,n)    for (int i(a); i<n ;  i++)
void fastIO();

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    rep(i,n)
        cin>>a[i];

    bool isDense(0);
    int step(0);

    rep(i,n-1)
    {
        int mx = max(a[i], a[i+1]);
        int mn = min(a[i], a[i+1]);

        while(mn*2 < mx)
        {
            step++;
            mn*=2;
        }
    }

    cout<<step<<endl;

}

signed main()
{
    fastIO();
    int T;
    cin >> T;
    while (T--)
        solve();
}

void fastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
