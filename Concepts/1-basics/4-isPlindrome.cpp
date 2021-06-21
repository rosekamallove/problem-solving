#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str);
bool isPalindrome2(string str);

string reverse(string str)
{
  string strRev;
  for(int i=str.size()-1; i>=0; --i)
  {
    strRev.push_back(str[i]);
  }
  return strRev;
}


int main()
{
  string str; cin>>str;
  cout<<isPalindrome(str)<<endl;
  cout<<isPalindrome2(str)<<endl;
}

bool isPalindrome(string str)
{
  bool check = 0;
  int i = 0;
  int size = str.size()-1;
  while(i<size)
  {
    if(str[i]==str[size]) check = 1;
    else check = 0;
    ++i;
    --size;
  }
  return check;
}
bool isPalindrome2(string str)
{
  if(reverse(str)==str) return 1;
  else return 0;
}
