#include<bits/stdc++.h>
using namespace std;
//print factorial % M where m=1e9+7
//1<= T <= 1e5;
//1<= N <= 1e5;

//what we can do is preCompute all the factorials and store it in an array.
const int M = 1e9+7;
const int N = 1e5+12;
long long fact[N];

int main()
{
  fact[0] = fact[1] = 1;
  int t(1); cin>>t;
  for(int i=1; i<N; ++i)
  {
    fact[i]=fact[i-1]*i;
  }
  while(t--)
  {
    int n; cin>>n;
    cout<<fact[n]<<endl;
  }
}

