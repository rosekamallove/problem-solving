#include <bits/stdc++.h>
using namespace std;
#define int long long
void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool is(0);
        int w1, w2, x1, x2, M;
        cin >> w1 >> w2 >> x1 >> x2 >> M;
        int change = (w2 - w1);

        if (change >= x1 * M and change <= x2 * M)
            is = 1;
        else
            is = 0;
        cout << is << endl;
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