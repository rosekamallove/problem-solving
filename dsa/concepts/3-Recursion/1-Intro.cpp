#include <bits/stdc++.h>
using namespace std;

/*
  --> we use recursion when we can solve the problem by breaking it into smaller problem.
  --> Or in other words, when we first have to solve for n then n-1 then n-2 and so on
  --> Finding n! will make everythin clear.
*/

int factorial(int n)
{
  if (n == 0)
    return 1;
  // cout<<n<<endl;//we notice that the number goes to negative.
  int smallOutput = factorial(n - 1);
  return n * smallOutput;
}

int main()
{
  //=> n! = n*(n-1)!
  //=> fact(n) = n*fact(n-1)
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    cout << factorial(n) << endl;
  }
}
