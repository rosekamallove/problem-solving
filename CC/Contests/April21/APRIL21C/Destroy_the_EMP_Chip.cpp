#include <bits/stdc++.h>
using namespace std;
#define int long long
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x, y) cout << #x << ": " << x << " " << #y << ": " << y << endl;

void solveT()
{
    int t, q, d;
    cin >> t >> q >> d;
    while (t--)
    {
        int x(0), y(0);
        cout << 1 << x << y << endl;
        string s;
        cin >> s;
        while (s != "O")
        {
            if (s == "PY")
            {
                x--;
                cout << 1 << x << y << endl;
            }
            else if (s == "NY")
            {
                x++;

                cout << 1 << x << y << endl;
            }
            else if (s == "XP")
            {
                y--;
                cout << 1 << x << y << endl;
            }
            else if (s == "XN")
            {
                y++;
                cout << 1 << x << y << endl;
            }
            else if (s == "PP")
            {
                x--;
                y--;
                cout << 1 << x << y << endl;
            }
            else if (s == "PN")
            {
                x--;
                y++;
                cout << 1 << x << y << endl;
            }
            else if (s == "NP")
            {
                x++;
                y--;
                cout << 1 << x << y << endl;
            }
            else if (s == "NN")
            {
                x++;
                y++;
                cout << 1 << x << y << endl;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solveT();
}