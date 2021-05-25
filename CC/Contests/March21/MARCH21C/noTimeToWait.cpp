#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, x;
    cin >> n >> t >> x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    bool is = 0;
    for (int i = 0; i < n; i++)
    {
        if ((v[i] + x) == t)
            is = 1;
    }
    if (is)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
