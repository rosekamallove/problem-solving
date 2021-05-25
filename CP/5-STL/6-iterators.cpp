#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v = {1,2,4,5,6,7};

  vector<int> :: iterator it = v.begin();
  cout<<(*it)<<endl;

  for(it=v.begin(); it!=v.end(); it++)
  {
    //it++ -> Moves to next iterator
    //it+1 -> Moves to next location
    cout<<(*it)<<endl;
  }
}
