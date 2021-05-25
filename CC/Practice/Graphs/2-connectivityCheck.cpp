#include<bits/stdc++.h>
using namespace std;

/*
 * => Given a graph, tell if it is connected
 */
const int N = 1e5;
vector<int> adj[N];

bool visited[N];
int cnt(0);

void dfs(int node){
    visited[node] = true;
    cnt++;
    for(auto x : adj[node]){
        if(visited[x]) 
            continue;
        dfs(x);
    }
}/* O(n+m) */

int main(){
    /*
     * -> Problem with adjacency matrix is that it takes n*n space
     * -> Hence we use adjacency list
     */
    int n; cin>>n;//nodes
    int m; cin>>m;//edges

    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        //considering undirected
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1); //dfs from any node

    cout<<((cnt == n) ? "Connected" : "Not connected")<<endl;
}
