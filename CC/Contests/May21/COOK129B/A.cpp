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
    int n,m; cin>>n>>m;
    string st; cin>>st;
    int s[n];
    for(int i=0; i<n; i++){
        s[i] = st[i] - '0';
    }

    bool isAlive(0);
    for(int i=1; i<m+1; i++){
        if(isAlive){
            s[i] = 1;
            isAlive = 0;
        }
        if(s[i] == 0 and ((s[i+1] == 1 and s[i-1] == 0) or (s[i+1] == 0 and s[i+1] == 1))){
            isAlive = 1;
        }
    }

    for(int i=0; i<n; i++){
        cout<<s[i];
    }
    cout<<endl;
}

signed main(){
    fastIO();
    int T;
    cin >> T;
    while (T--)
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

