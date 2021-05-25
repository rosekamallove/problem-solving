#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x,y) cout << #x << ": " << x << #y << ": " << y << endl;

void solve()
{
    int x,r,m; cin>>x>>r>>m;
    r*= 60; m*=60;
    int req(0); 
    req += min(x,r);
    r -= min(x,r);
    req += 2*r;
    if(req<=m) 
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

        int t; cin>>t;
        while(t--)
	        solve();
}
