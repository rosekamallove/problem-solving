#include<vector>
#include<iostream>
using namespace std;

/*
 * => Input:
 *      -> Given n and m in the first line and m line follows,
 *         each line contains a u and a v,
 *         n is the number of nodes in the graph and,
 *         m is the number of edges in the graph.
 */

void adjacencyMatrix()
{
    /*
     * => This first way to store the values listed above will be to use a adjacency matrix:
     */

    int n, m; cin>>n>>m;

    int adj[n+1][m+1];
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
        adj[i][j]=0;

    for(int i=1; i<m; i++)
    {
        int u,v; cin>>u>>v;
        //if undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void adjacencyList()
{
    int n,m; cin>>n>>m;

    //an adjacencylist
    vector<int> adj[n+1];

    /*
     * If the graph is weighted we'll make 
     * a vector of pair and will push the 
     * weight with the edge too.
     */
    vector<pair<int,int>> adj2[n+1];

    for(int i=0;i<n;i++)
    {
        int u, v; cin>>u>>v;
        //if undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
