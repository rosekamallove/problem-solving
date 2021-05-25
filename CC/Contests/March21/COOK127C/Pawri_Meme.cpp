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
        string str;
        cin >> str;
        size_t idx = 0;
        while (1)
        {
            idx = str.find("party", idx);
            if (idx == -1)
                break;

            str.replace(idx, 5, "pawri");
            idx += 5;
        }
        cout << str+'s' << endl;
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
