/***** DFS *****/
#include<iostream>
#include<vector>
using namespace std;

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

bool find_path(int cur, int destination){
    if(cur == destination){
        return true;
    }
    visited[cur] = true;
    bool found(0);
    for(auto adj_vertex : adj[cur]){
        if(visited[adj_vertex])
            continue;
        if(find_path(adj_vertex, destination)) 
            found = 1;
    }
    return found;
}

int main(){

    int n; cin>>n;//nodes
    int m; cin>>m;//edges

    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        //considering undirected
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
