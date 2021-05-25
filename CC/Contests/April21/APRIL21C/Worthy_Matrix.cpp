#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x, y) cout << #x << ": " << x << " " << #y << ": " << y << endl;

int midOfTwo(int a, int b)
{
    return a + (b - a) / 2;
}

int power(int x, int y)
{
    int res(1);
    while (y > 0)
    {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}

void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int pf[n][m];

        for (int i(0); i <= n; i++)
            for (int j(0); j <= m; j++)
                pf[i][j] = 0;

        for (int i(0); i <= n; i++)
            for (int j(0); j <= m; j++)
                cin >> pf[i][j];

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pf[i][j] += pf[i][j - 1];

        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                pf[i][j] += pf[i - 1][j];

        int count(0);

        for (int edge(1); edge <= n; edge++)
        {
            for (int i(1); i <= n - edge + 1; i++)
            {
                int low(1);
                int high(m - edge + 1);
                int mid;
                int p;
                int is(0);

                while (low <= high)
                {
                    mid = midOfTwo(low, high);
                    int sum = pf[i + edge - 1][mid + edge - 1] - pf[i + edge - 1][mid - 1] - pf[i - 1][mid + edge - 1] + pf[i - 1][mid - 1];

                    if (sum >= k * edge * edge)
                    {
                        high = mid - 1;
                        p = mid;
                        is = 1;
                    }
                    else
                        low = mid + 1;
                }
                if (is == 1)
                    count += (m - edge - p + 2);
            }
        }
        cout << count << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solveT();
}