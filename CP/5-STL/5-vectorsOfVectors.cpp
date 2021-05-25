#include<bits/stdc++.h>
using namespace std;

void printVect(vector<int> &v)
{
  for(int i=0; i<v.size(); i++)
  {
    cout<<v[i]<<endl;
  }
}

int main()
{
  int N; cin>>N;
  vector<vector<int>> v; //a matrix with dynamic no of rows and coloumns
  
  for(int i=0; i<N; i++)
  {
    int n; cin>>n;
    v.push_back(vector<int>());
    for(int j=0; j<n; j++)
    {
      int x; cin>>x;
      v[i].push_back(x);
    }
    v.push_back(v[i]);
  }

  for(int i=0; i<v.size(); i++) 
  {
    printVect(v[i]);
  }
}
