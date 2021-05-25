#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n; cin>>n;
  int ar[n];
  for(int i=0; i<n; i++) cin>>ar[i];

  int sum =0;
  for(int i=0; i<n; i++) sum += ar[i];

  cout<<sum<<endl;
}

