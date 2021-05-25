#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 12;
#define pb push_back
#define endl "\n"
#define int long long
#define deb(x) cout << #x << ": " << x << endl;
#define F first
#define S second
#define rep(i, n)              \
    for (int i(0); i < n; i++) \
        ;
#define rap(i, a, n) for (int i(a); i < n; i++)

vector<int> hsh;
vector<int> pr;

void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int mx(INT_MIN);
        for (int i(0); i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a <= x)
            {
                mx = max(mx, b);
            }
        }
        cout << mx << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // solve();
    solveT();
}
