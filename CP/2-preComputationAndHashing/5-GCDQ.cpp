// https://www.codechef.com/problems/GCDQ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x,y) cout << #x << ": " << x << #y << ": " << y << endl;
#define rep(i,n) for(int i(0); i<n; i++)
#define rap(i,a,n) for(int i(a); i<n; i++)

void solve()
{
    int T; cin>>T;
    while(T--)
    {
        int n, q; cin>>n>>q;
        int arr[n+1];
        arr[0]=0;
        for(int i=1; i<=n; i++)
            cin>>arr[i];

        while(q--)
        {
            int l,r; cin>>l>>r;
            int gcd=0;

            for(int i=1; i<l; i++)
                gcd = __gcd(gcd, arr[i]);

            for(int i=r+1; i<=n; i++)
                gcd = __gcd(gcd, arr[i]);

            cout<<gcd<<endl;
        }
    }
}


void solveOptimized()
{
    int T; cin>>T;
    while(T--)
    {
        int n,q; cin>>n>>q;
        int arr[n+1], forwardGCD[n+1], backwardGCD[n+1];

        forwardGCD[0] = backwardGCD[n+1] = 0;

        for(int i=1; i<=n; i++)
            cin>>arr[i];

        for(int i=1; i<=n; i++)
            forwardGCD[i] = __gcd(forwardGCD[i-1], arr[i]);

        for(int i=n; i>=1; i--)
            backwardGCD[i] = __gcd(backwardGCD[i+1], arr[i]);

        while(q--)
        {
            int l, r; cin>>l>>r;
            cout<<__gcd(forwardGCD[l-1],backwardGCD[r+1])<<endl;
        }
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    solveOptimized();
}
