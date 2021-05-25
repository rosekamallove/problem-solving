#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        int xr(0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                xr = xr ^ (i + j + K + 2);
            }
        }
        cout << xr << endl;
    }
}

void solve()
{
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solveT();
    //solve();
}