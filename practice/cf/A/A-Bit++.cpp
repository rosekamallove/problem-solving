#include "bits/stdc++.h" 
using namespace std;

#define fastIO()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define endl "\n"
#define mod %

#ifndef ONLINE_JUDGE
#define testCase       cout<<"<<<<<<= TestCase =>>>>>>"<<endl;
#define tdeb(x,y)      cout <<'('<< #x<<','<<#y<<") ++> "; print(x,y)
#define deb(x)         cout << #x << " ++> "; print(x)
#else
#define testCase       
#define tdeb(x,y)
#define deb(x)
#endif

#define rep(i,n)       for (int i(0); i<n ;  i++)
#define rip(i,n)       for (int i(1); i<=n;  i++)
#define rap(i,a,n)     for (int i(a); i<n ;  i++)
template<typename T>   void print(vector<T> v);
template<typename T>   void print(T n);
template<typename T,   typename Tt> void print(T n, Tt m);
//----------------------------------------------------------------------------------------------------//


void solve(){
    int T,x(0); cin>>T;
    while(T--){
        string s; cin>>s;
        if(s == "++X" or s=="X++")
            ++x;
        if(s == "--X" or s=="X--")
            --x;
    }
    cout<<x<<endl;
}

signed main(){
    fastIO();
    solve();
}


//----------------------------------------------------------------------------------------------------//
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
