#include <iostream>
using namespace std;

int countMinStepsToOne(int n) {
  if (n <= 1)
    return 0;
  int x = countMinStepsToOne(n - 1);
  int z(INT_MAX), y(INT_MAX);
  if (n % 2 == 0)
    z = countMinStepsToOne(n / 2);
  if (n % 3 == 0)
    y = countMinStepsToOne(n / 3);

  return min(x, min(z, y)) + 1;
}

int minStepsHelper(int n, int *ans) {
  if (n <= 1)
    return 0;
  if (ans[n] != -1)
    return ans[n];

  int x = countMinStepsToOne(n - 1);
  int z(INT_MAX), y(INT_MAX);
  if (n % 2 == 0)
    z = countMinStepsToOne(n / 2);
  if (n % 3 == 0)
    y = countMinStepsToOne(n / 3);

  ans[n] = min(x, min(z, y)) + 1;
  return ans[n];
}

int countMinStepsToOne_2(int n) {
  int *ans = new int[n + 1];
  for (int i = 0; i <= n; i++)
    ans[i] = -1;

  return minStepsHelper(n, ans);
}

int main() {
  int n;
  cin >> n;
  cout << countMinStepsToOne(n);
}
