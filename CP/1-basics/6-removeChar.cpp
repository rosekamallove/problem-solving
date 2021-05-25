#include<bits/stdc++.h>
using namespace std;

void removeChar(string s1, string s2);

int main()
{
  string s1,s2; cin>>s1>>s2;
  for(int i=0; i<(s1.size()-1); ++i)
  {
    for(int j=0; j<(s2.size()-1); ++j)
    {
      if(s1[i]==s2[j]) s1.erase(s1.begin() +i);
    }
  }
  cout<<s1;
}

