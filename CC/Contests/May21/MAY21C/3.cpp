#include "bits/stdc++.h"
using namespace std;

const int N = 1e9+7;

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

int gcdExtended(int a, int b, int *x, int *y);
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);

    if (g != 1)
        return -1;

    return (x%m + m) % m;
}

int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
        return -1;
    else
        return (inv*a)%m;
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}


int power(int x, unsigned int y, int p)
{
    int res = 1; 
    x = x % p; 

    if (x == 0) 
        return 0; 

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

void solve()
{
    int n; cin>>n;
    int noOfEven = power(2,n,N);
    cout<<modDivide(noOfEven, 2, N)<<endl;
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
