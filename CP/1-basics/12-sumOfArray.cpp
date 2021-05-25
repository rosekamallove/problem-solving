/*
 * Givent t test cases return the sum of array
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int ll
#define fn(i,a,b) for (int i=a; i<=a; i++)

void fileIO();

void solve()
{
  int n; cin>>n;
  int arr[n];
  int sum =0;
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
    sum+=arr[i];
  }
  cout<<sum<<endl;
}


int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin>>t;
  while(t--) solve();

  return 0;
}

void fileIO()
{
  freopen("input.txt", "r", stdin);
  cin.tie(0);
}
