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

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        vector<int> hsh(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (v[j] > v[i])
                    break;
                if (v[j] == v[i])
                    hsh[i]++;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (v[j] > v[i])
                    break;
                if (v[j] == v[i])
                    hsh[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << hsh[i] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // solve();
    solveT();
}