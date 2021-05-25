#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x,y) cout << #x << ": " << x << #y << ": " << y << endl;

void solve()
{
    int n; cin>>n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        v.push_back(x);
    }
    int sum(0);
    int cnt(0);

    for(int i=0; i<n; i++)
        sum+=v[i];

    if(sum%2==0) 
        cout<<0<<endl;
    else 
    {
        for(int i=0; i<n; i++)
        {
            if(v[i]==2)
            {
                cnt++;
                break;
            }
        }
        if(cnt!=0) 
            cout<<1<<endl;
        else 
            cout<<-1<<endl;
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

        int t; cin>>t;
        while(t--)
	        solve();
}
