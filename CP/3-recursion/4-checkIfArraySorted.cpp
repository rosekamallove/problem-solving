#include<bits/stdc++.h>
using namespace std;

bool isSorted2(int arr[], int size)
{
  if(size==0 || size==1) return 1;

  bool isSmallerOutput = isSorted2(arr+1, size-1);
  if(!isSmallerOutput) return 0;
  else return 1;
  if(arr[0]>arr[1]) return 0;
  else return 1;


}

bool isSorted(int arr[], int size)
{
  if(size==0 || size==1) return 1;
  if(arr[0]<arr[1]) return 1;
  else return 0;
  
  return isSorted(arr+1, size-1);
}

int main()
{
  int n; cin>>n;
  int * a = new int[n];
  for(int i=0; i<n; i++) cin>>a[i];

  cout<<isSorted(a, n)<<endl;
}

