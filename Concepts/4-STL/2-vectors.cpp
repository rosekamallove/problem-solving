#include<iostream>
#include<vector>
using namespace std;

void printVect(vector<int> v)
{
  for(int i=0; i< v.size(); ++i)
  {
    cout<<v[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  vector<int> v;

  int n; cin>>n; 
  for(int i=0; i<n; i++)
  {
    int x; cin>>x;
    v.push_back(x);
  }

  printVect(v);

  vector<int> v2(5, 4);
  v2.push_back(8);

  v2.pop_back();
  printVect(v2);


  vector<int> v3 = v;// O(n)
}
