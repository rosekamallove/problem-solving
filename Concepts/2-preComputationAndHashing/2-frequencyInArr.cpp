/*
Given and array a if N integers, Given Q queries
and in each quesry given a number x, print 
count of that number in array.

Constraints:
1 <= N <= 1e7
1 <= a[i] <= 1e7
1 <= Q <= 1e5

*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+12;
long long harr[N];

int main()
{
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
    harr[arr[i]]++;
  }
  int t; cin>>t;
  while(t--)
  {
    int x; cin>>x;
    cout<<harr[x];
  }
}

