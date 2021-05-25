#include<bits/stdc++.h>
using namespace std;

int digitSum(int n)
{
  int sum = 0;
  while(n)
  {
    sum += n%10;
    n = n/10;
  }
  return sum;
}

int main()
{
  int n, m; cin>>n>>m;
  cout<<digitSum(n)+digitSum(m)<<endl;
}

