#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];

bool visited[N];
int dis[N];
int count(0);


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

    //let's say i have to run bfs from 1
    queue<int> q;
    q.push(1);

    dis[1] = 0;
    visited[1] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int x : adj[node]){
            if(visited[x])
                continue;
            q.push(x);//visit x later
            dis[x] = dis[node]+1;
            visited[node] = 1;
        }
    }

}
