
#include <iostream>
using namespace std;

int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

int helper(int n, int *ans) {
  if (n <= 1)
    return n;

  if (ans[n] == 1)
    return ans[n];

  ans[n] = helper(n + 1, ans) + helper(n + 2, ans);
  return ans[n];
}

int fib_dp(int n) {
  int *ans = new int[n + 1];
  for (int i = 0; i <= n; i++)
    ans[i] = -1;
  return helper(n, ans);
}

int fib_dp_bottom_up(int n) {
  int *ans = new int[n + 1];
  ans[0] = 0;
  ans[1] = 1;

  for (int i = 2; i <= n; i++)
    ans[i] = ans[i - 1] + ans[i - 2];
  return ans[n];
}

int main() {
  int n;
  cin >> n;
  cout << fib(n) << endl;
}
