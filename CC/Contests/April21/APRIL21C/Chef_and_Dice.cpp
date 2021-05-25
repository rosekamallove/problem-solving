#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x, y) cout << #x << ": " << x << " " << #y << ": " << y << endl;

void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int rm(n % 4);
        int ans(0);

        int one = 20;
        int two = 2 * (6 + 5 + 4 + 3);
        int three = (2 * (6 + 5 + 4 + 3)) + 6 + 5 + 4;
        int four = 4 * (6 + 5 + 4);

        if (n == 1)
            ans = one;
        else if (n == 2)
            ans = two;
        else if (n == 3)
            ans = three;
        else if (n == 4)
            ans = four;

        else if (n >= 5)
        {
            ans = ((n - rm) / 4) * 44;
            if (rm == 0)
                ans += 16;
            else if (rm == 1)
                ans += 32;
            else if (rm == 2)
                ans += 44;
            else if (rm == 3)
                ans += 55;
        }
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solveT();
}