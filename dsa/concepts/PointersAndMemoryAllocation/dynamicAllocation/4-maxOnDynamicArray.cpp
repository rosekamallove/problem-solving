#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n; cout<<"Enter the number of element: "<<endl;
  cin>>n;
  int * a = new int[n];

  for(int i=0; i<n; i++) cin>>a[i]; //-> *(a+i)
  
  int max = INT_MIN;
  for(int i=0; i<n; i++)
  {
    if(max < a[i]) max = a[i];
  }
 cout<<"Max: "<<max<<endl;
}

