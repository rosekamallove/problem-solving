#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
void solveT()
{
    for (int i = 1; i < 1e6; i++)
    {
        if (sqrt(i) == (int)sqrt(i))
        {
            v.push_back(i);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l = 1, r = 1000000;
        bool is(0);
        int i(1);
        do
        {
            cout << v[i] << endl;
            cin >> is;
            i++;
        } while (!is and i < 1e6);
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solveT();
    //solve();
}