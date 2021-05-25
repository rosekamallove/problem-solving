#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7;
const int N = 1e5 + 12;
long long hsh[N];
long long pr[N];

void solveT()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N, M, K;
    cin >> N >> M >> K;
    int xr(0);

    for (int i = 1; i <= N; i++)
    {
      if (min(i, M) % 2 == 1)
        xr ^= K + i + 1;
    }

    for (int i = 2; i <= M; i++)
    {
      if (min(N, M - i + 1) % 2 == 1)
        xr ^= K + i + N;
    }
    cout << xr << endl;
  }
}
int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  //solve();
  solveT();
}
