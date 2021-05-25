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
        int n;
        cin >> n;
        vector<int> v;
        int sum(0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int cnt(0);
        for (int i = 0; i < n; i++)
            sum += v[i];

        if (sum % 2 == 0)
            cout << 0 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 2)
                {
                    cnt++;
                    break;
                }
            }
            if (cnt != 0)
                cout << 1 << endl;
            else
                cout << -1 << endl;
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
    cout.tie(0);
    // solve();
    solveT();
}