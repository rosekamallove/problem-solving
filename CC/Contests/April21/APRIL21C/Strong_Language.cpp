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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int count(0);
        bool is(0);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                count++;
                if (count >= k)
                {
                    is = 1;
                }
            }
            else if (s[i] != '*')
                count = 0;
        }
        if (is)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solveT();
}