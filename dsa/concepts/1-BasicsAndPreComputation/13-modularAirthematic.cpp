#include <bits/stdc++.h>
using namespace std;

int main()
{
  /*
  => (a+b)%M = ((a%M) + (b%M))%M
  => (a*b)%M = ((a%M) * (b%M))%M
  => (a-b)%M = ((a%M) - (b%M) + M)%M
  => (a/b)%M = ((a%M)*(b^-1)%M)%M :b^-1 is the multiplicative inverse

  Usually modulo given is 1e9+7, this is because:
  ->very close to integer max
  ->mulitplicative inverse, as this number is prime
  */

  // Given N, print its factorial
  // print modulo M

  int n;
  cin >> n;
  long long fact = 1;
  int m = 47;
  for (int i = 2; i <= n; ++i)
    fact = (fact * i) % m;
  cout << fact;
}
