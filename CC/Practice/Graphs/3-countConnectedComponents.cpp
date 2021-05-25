#include<bits/stdc++.h>
using namespace std;

/*
 * => Count the number of connected componets in a graph
 */

const int N = 1e5;
vector<int> adj[N];

bool visited[N];

void dfs(int node){
    visited[node] = 1;
    for(auto x : adj[node]){
        if(visited[x]) 
            continue;
        dfs(x);
    }
}

int main(){
    int n,m,componets(0); cin>>n>>m;

    for(int i=0;i< m; i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i< n; i++){
        if(visited[i])
            continue;
        dfs(i);
        componets++;
    }
    cout<<componets<<endl;
}
