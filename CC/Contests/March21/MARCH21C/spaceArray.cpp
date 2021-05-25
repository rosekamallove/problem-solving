#include <bits/stdc++.h>
using namespace std;

#define int long long

void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int f(0), s(0);
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if (i + 1 < v[i])
            {
                s = 1;
                break;
            }
            f += (i + 1 - v[i]);
        }
        if (s == 1)
            cout << "Second" << endl;
        else
        {
            if (f % 2 == 1)
                cout << "First" << endl;
            else
                cout << "Second" << endl;
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //fileIO();
    solveT();
}

void fileIO()
{
#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}
