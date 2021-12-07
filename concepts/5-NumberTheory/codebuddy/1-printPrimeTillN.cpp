#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
  for(int i=2; i<n+1; i++)
  {
    if(n%i==0) return 0;
  }
  return 1;
}

int main()
{
  int n; cin>>n;

  for(int i =1; i<n+1; i++)
  {
    if(i==1) cout<<"yes: "<<1<<endl;
    if(i==2) cout<<"yes: "<<2<<endl;
    if(checkPrime(i))
      cout<<"Yes: "<<i<<endl;
  }
}
