#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x, y) cout << #x << ": " << x << #y << ": " << y << endl;
#define rep(i, n) for (int i(0); i < n; i++)
#define rep2(j, n) for (int j(0); j < n; j++)
#define rip(i, n) for (int i(1); i <= n; i++)
#define rap(i, a, n) for (int i(a); i < n; i++)

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 or i == n - 1) and j % 2 == 0) {
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (i % 2 == 0 and i != n - 2) {
            arr[i][0] = 1;
            arr[i][m - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}

