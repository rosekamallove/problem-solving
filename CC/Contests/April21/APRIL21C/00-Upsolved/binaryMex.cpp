#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x,y) cout << #x << ": " << x << #y << ": " << y << endl;

//DynamicProgramming

void solve()
{
    string s; cin>>s;
    int n(s.length());

    string ans("");

    for(int i=0; i<n; i++)
        if(s[i]=='0') ans = "1";
        else if(s[i]=='1') ans = "0";
        else ans = "";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

        int t; cin>>t;
        while(t--)
	        solve();
}
