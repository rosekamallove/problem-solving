#include<bits/stdc++.h>
using namespace std;

void printVec(vector<pair<int,int>> &v)
{
  cout<<"size: " <<v.size()<<endl;
  for(int i=0; i<v.size(); ++i)
  {
    cout<<v[i].first<<" "<<v[i].second;
  }
}

int main()
{
  int n; cin>>n;

  //vector of pair
  vector<pair<int,int>> v = {{1,3},{2,3},{3,5}};
  printVec(v);
  
  for(int i=0; i<n; ++i)
  {
    int x,y; cin>>x>>y;
    v.push_back({x,y});
  }
  printVec(v);
}
