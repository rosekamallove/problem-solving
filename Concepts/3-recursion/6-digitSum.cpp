#include<iostream>
using namespace std;

int digitSum2(int n)
{
  if(n==0) return 0;
  return digitSum2((n/10)+(n%10));
}

int digitSum(long long n, long long sum =0)
{
  if(n==0) return sum+=0;
  sum+=n%10;
  return digitSum(n/10, sum);
}

int main()
{
  int n; cin>>n;
  cout<<digitSum(n)<<endl;
}
