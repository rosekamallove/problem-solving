#include<iostream>
using namespace std;

int arrSum(int arr[], int size)
{
  if(size<0) return 0;
  return arr[size] + arrSum(arr, size-1);
}


int main()
{
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n; i++) cin>>arr[i];
  cout<<arrSum(arr,n-1)<<endl;
}
