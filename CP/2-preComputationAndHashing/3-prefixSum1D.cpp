/*
Given an array a of N integers. Given Q queries 
and in each query given L and R print sum of 
array elements from index L to R(L,R included)
 * */
#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;
const int N = 1e5+12;
int hsh[N];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin>>n;
  int arr[n];
  for(int i=1; i<=n; i++)
  {
    cin>>arr[i];
    hsh[i]=hsh[i-1]+arr[i];
  }

  int t; cin>>t;
  while(t--)
  {
    int l,r; cin>>l>>r;
    cout<<hsh[r]-hsh[l-1]<<endl;
  }

}

