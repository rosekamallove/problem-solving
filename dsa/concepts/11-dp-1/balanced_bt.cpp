#include <iostream>
using namespace std;

int helper(int n, int ans[]) {
  if (n <= 1) {
    return 1;
  }

  if (ans[n] != -1)
    return ans[n];

  int mod = 1e9 + 7;
  int x = helper(n - 1, ans);
  int y = helper(n - 2, ans);

  long long int temp1 = ((long long int)x * x) % mod;
  long long int temp2 = (2 * (long long int)x * y) % mod;
  long long int a = (temp1 + temp2) % mod;

  ans[n] = a;

  return ans[n];
}

int balancedBTs(int n) {
  int ans[n + 1];
  for (int i = 0; i <= n; i++) {
    ans[i] = -1;
  }
  return helper(n, ans);
}

int main() {
  int h;
  cin >> h;
  cout << balancedBTs(h);
}
