#include<bits/stdc++.h>
using namespace std;

string reverse(string str)
{
  string strRev;
  for(int i=str.size(); i>=0; --i)
  {
    strRev.push_back(str[i]);
  }
  return strRev;
}

int main()
{
  string str; cin>>str;
  cout<<reverse(str)<<endl;
}

