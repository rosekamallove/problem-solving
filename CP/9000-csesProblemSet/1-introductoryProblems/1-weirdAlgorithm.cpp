#include<bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main()
{
  int n; cin>>n;
  cout<<n<<" ";

  while(true)
  {
    if(n==1) break;
    else if(n%2==0)
    {
      n/=2;
      cout<<n<<" ";
    }
    else
    {
      n=(n*3)+1;
      cout<<n<<" ";
    }
  }

  return 0;
}

