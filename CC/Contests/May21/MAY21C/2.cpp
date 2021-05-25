#include "bits/stdc++.h"
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define endl "\n"

#ifndef ONLINE_JUDGE
#define tdeb(x,y)
#define deb(x)
#else
#define tdeb(x,y)     cout <<'('<< #x<<','<<#y<<") ++> "; print(x,y)
#define deb(x)        cout << #x << " ++> "; print(x)
#endif

#define rep(i,n)      for (int i(0); i<n ;  i++)
#define rip(i,n)      for (int i(1); i<=n;  i++)
#define rap(i,a,n)    for (int i(a); i<n ;  i++)

template<typename T> void print(vector<T> v);
template<typename T> void print(T n);
template<typename T, typename Tt> void print(T n, Tt m);

bool is(int a, int d, int x)
{
    if (d == 0)
        return (x == a);

    return ((x - a) % d == 0 && (x - a) / d >= 0);
}

void solve()
{
    int n,x,k;
    cin>>n>>x>>k;

    bool isit(0);

    if((x%k==0) or ((n+1-x)%k==0))
        isit = 1;
    
    cout<<(isit ? "YES" : "NO")<<endl;
}

signed main()
{
    fastIO();
    int T;
    cin >> T;
    while (T--)
        solve();
}

template<typename T, typename Tt> void print(T n, Tt m){
    cout<<'{'<<n<<','<<m<<'}'<<endl;
}

template<typename T> void print(T n){
    cout<<n<<endl;
}

template<typename T> void print(vector<T> v) {
    cout<<'[';
    for(auto val : v){
        cout<<val;
        cout<<' ';
    }
    cout<<']'<<endl;
}
