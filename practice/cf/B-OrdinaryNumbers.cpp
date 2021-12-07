#include <bits/stdc++.h>
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

int count_same_digit(int L, int R){
    int tmp = 0, ans = 0;
    int n = log10(R) + 1;
  
    for (int i = 0; i < n; i++) {
        tmp = tmp * 10 + 1;
        for (int j = 1; j <= 9; j++) {
            if (L <= (tmp * j)
                && (tmp * j) <= R) {
                ans++;
            }
        }
    }
    return ans;
}


void solve(){
    int n; cin>>n;
    cout<<count_same_digit(1,n)<<endl;
}

signed main(){
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
