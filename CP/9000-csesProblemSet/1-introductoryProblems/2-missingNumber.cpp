#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
  int n; cin>>n;
  int arr[n-1];

  for(int i=0; i<n-1; i++) cin>>arr[i];

  sort(arr,arr+n);


  for(int i=1; i<=n; i++)
  {
    if(arr[i-1]!=i)cout<<i<<endl;
  }
  return 0;
}

