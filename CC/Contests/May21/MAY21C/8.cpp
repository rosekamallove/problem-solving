#include "bits/stdc++.h"
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define endl "\n"

#ifndef ONLINE_JUDGE
#define tdeb(x,y)     cout <<'('<< #x<<','<<#y<<") ++> "; print(x,y)
#define deb(x)        cout << #x << " ++> "; print(x)
#else
#define tdeb(x,y)
#define deb(x)
#endif

#define rep(i,n)      for (int i(0); i<n ;  i++)
#define rip(i,n)      for (int i(1); i<=n;  i++)
#define rap(i,a,n)    for (int i(a); i<n ;  i++)

template<typename T> void print(vector<T> v);
template<typename T> void print(T n);
template<typename T, typename Tt> void print(T n, Tt m);
//-----------------------------------------------------------------------------------------------------//
//

vector<int> hsh(1e6);

int power(int x, int y)
{
    int res = 1;

    while (y)
    {
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}


void precompute()
{
    for(int k=1; k<=1e6; k++)
        for(int i=1; i<=2*k; i++)
            hsh[i] = GCD((k+i*i), (k+power((i+1),2)));
}

void solve()
{
    int k; cin>>k;
    cout<<hsh[2*k+1]<<endl;
}

signed main()
{
    fastIO();
    precompute();
    int T; cin>>T;
    while(T--)
        solve();
}

//-----------------------------------------------------------------------------------------------------//

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
