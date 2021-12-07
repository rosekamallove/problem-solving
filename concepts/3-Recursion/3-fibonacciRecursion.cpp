#include<bits/stdc++.h>
using namespace std;
// fib(n) = 0 1 2 3 5 8 13 ...
// fib(n) = fib(n-1) + fib(n-2)

/*
=> Extended PMI:
-> Base case: f(0) or f(1) is true
-> Ist  case: Assume f(i) is true for all i<=k
-> IInd case: Use Ist case to prove f(k+1) is true.
  */

int fib(int n)
{
  if(n==0) return 0;
  if(n==1) return 1;//as we want two funciton calls hence two base case
  //or think of it this way that to find nth fib we at least should know the first two
  int smallOutput1 = fib(n-1);
  int smallOutput2 = fib(n-2);

  return smallOutput1 + smallOutput2;
}

int main()
{
  int n; cin>>n;
  cout<<fib(n)<<endl;
}

