// find the frequency of names

#include<bits/stdc++.h>
using namespace std;

int main()
{
  map<string,int> m;
  int n; cin>>n;
  string a[n];
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
    m[a[i]]++;
  }
  map<string, int> :: iterator it;

  for(it = m.begin();it!=m.end(); it++)
  {
    cout<<it->first<<' '<<it->second<<endl;
  }
}
