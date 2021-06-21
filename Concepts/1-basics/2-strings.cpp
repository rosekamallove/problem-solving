#include<bits/stdc++.h>
using namespace std;

int main()
{
  string str = "hello";
  string str2; cin>>str2;

  if(str==str2) cout<<"Equal\n";
  else cout<<"Not Equal\n";

  for(int i=0; i<str.size(); ++i) cout<<str[i];


  string str3;
  getline(cin, str3);
  cout<<str3<<endl;

}

