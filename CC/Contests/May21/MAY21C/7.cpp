#include "bits/stdc++.h" 
using namespace std;

const int N = 1e9+7;
#define fastIO()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define endl "\n"
#define mod %

#define testCase       cout<<"<<<<<<<<<<<<<<<=TestCase=>>>>>>>>>>>>>>>>>>"<<endl;
#ifndef ONLINE_JUDGE
#define tdeb(x,y)      cout <<'('<< #x<<','<<#y<<") ++> "; print(x,y)
#define deb(x)         cout << #x << " ++> "; print(x)
#else
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

const int M = 3e5 + 5;

vector<int> adj[M], subVal, val;
vector<pair<int, int>> ch;

void dfs(int now, int last = -1)
{
    for(auto x : adj[now])
    {
        if(x==last)
            continue;
        dfs(x, now);
    }

    ch.clear();
    for(auto x : adj[now])
    {
        if(x != last)
            ch.emplace_back(subVal[x], x);
    }
    sort(rbegin(ch), rend(ch));

    int token = 1;
    for(auto [_val, id] : ch)
        val[id] = token++;
    for(auto x : adj[now])
    {
        if(x != last)
            subVal[now] += val[x] * subVal[x];
    }
}

void solve()
{
    int n,x; cin>>n>>x;
    subVal.assign(n, 1), val.assign(n,0);
    rep(i,n)
        vector<int>().swap(adj[i]);

    rep(i,n-1)
    {
        int u, v; cin>>u>>v, --u, --v;
        adj[u].emplace_back(v), adj[v].emplace_back(u);
    }
    dfs(0);

    cout<<subVal[0]%N*x%N<<endl;
}

signed main()
{
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
