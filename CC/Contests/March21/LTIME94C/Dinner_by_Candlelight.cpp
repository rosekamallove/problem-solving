#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 12;
#define int long long
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
        int a, y, x;
        cin >> a >> y >> x;
        if (a >= y)
            cout << x * y << endl;
        else
            cout << x * a + 1 << endl;
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