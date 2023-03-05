#include <iostream>
using namespace std;

int minCostHelper(int **input, int m, int n, int i, int j,
                  int ans[m + 1][n + 1]) {
  if (i == m - 1 and j == n - 1)
    return input[i][j];

  if (i >= m or j >= n)
    return INT_MAX;

  if (ans[i][j] != -1)
    return ans[i][j];

  int x = minCostHelper(input, m, n, i + 1, j, ans);
  int y = minCostHelper(input, m, n, i, j + 1, ans);
  int z = minCostHelper(input, m, n, i + 1, j + 1, ans);

  ans[i][j] = input[i][j] + min(x, min(y, z));

  return ans[i][j];
}

int minCostPath(int **input, int m, int n) {
  int ans[m + 1][n + 1];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      ans[i][j] = -1;
  return minCostHelper(input, m, n, 0, 0, ans);
}

int main() {
  int **arr, n, m;
  cin >> n >> m;
  arr = new int *[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[m];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  cout << minCostPath(arr, n, m) << endl;
}
