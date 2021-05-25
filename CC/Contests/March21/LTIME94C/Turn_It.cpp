#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 12;
#define pb push_back
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x, y) cout << #x << ": " << x << " " << #y << ": " << y << endl;
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
        float u, v, a, s;
        cin >> u >> v >> a >> s;

        if (v == u)
            cout << "Yes" << endl;
        else
        {
            if ((u * u) - (2 * a * s) <= v * v)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

void solve()
{
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // solve();
    solveT();
}