#include<iostream>
using namespace std;

void selectionSort(int a[], int n)
{
  for(int i=0; i<n; i++)
  {
    int minIndex=i;
    for(int j=i+1; j<n; ++j)
    {
      if(a[j]<a[minIndex])
      {
        minIndex=j;
      }
    }
    swap(a[i], a[minIndex]);
  }
}


int main()
{
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n; i++) cin>>arr[i];
}
