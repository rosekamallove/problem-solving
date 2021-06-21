#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m; cin>>n>>m;
    vector<int> adj[n+1];

    for(int i=0; i<n+1; i++)
    {
        int u, v; cin>>u>>v;
        adj[v].push_back(v);
        adj[u].push_back(u);
    }
}
