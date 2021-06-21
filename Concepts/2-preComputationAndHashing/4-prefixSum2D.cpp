/*

 Given 2d array a of N*N integers. Given Q queries and in each query
 given a,b,c and d print sum of square represented by (a,b) as top
 left point and (c,d) as bottom right point

Constraints:
1 <=N<=1e3
1 <=a[i][j]<=1e9
1 <=Q<=1e5
1 <=a,b,c,d<=N

 */
#include<iostream>
using namespace std;

const int N = 1e3;
long long pf[N] [N];

int main()
{
  int n; cin>>n;
  int arr[n][n];

  for(int i=1; i<=n; i++)
    for(int j=1; i<=n; i++)
    {
      cin>>arr[i][j];
      pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];//formula for prefix sum of 2d array
    }

  int t; cin>>t;
  while(t--)
  {
    int a,b,c,d; cin>>a>>b>>c>>d;
    cout<<pf[c][d]-pf[a-1][d]-pf[c][b-1]+pf[a-1][b-1];
  }

}
