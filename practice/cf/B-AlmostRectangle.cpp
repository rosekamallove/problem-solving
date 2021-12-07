#include "bits/stdc++.h"
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"

void solve()
{
    int n; cin>>n;
    char a[n][n];

    pair<int,int> one, two;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }

    bool b(0);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(a[i][j] == '*' and !b)
            {
                one = {
                    i,
                    j
                };
                b = 1;
            }
            else if(a[i][j] == '*' and b)
            {
                two ={
                    i,
                    j
                };
            }
        }

    if (one.first == two.first) 
    {
        if (one.first == 0) 
            a[one.first + 1][one.second] = a[one.first + 1][two.second] = '*';
        else 
            a[one.first - 1][one.second] = a[one.first - 1][two.second] = '*';
    }
    else if (one.second == two.second) 
    {
        if (one.second == 0) 
            a[one.first][one.second + 1] = a[two.first][two.second + 1] = '*';
        else 
            a[one.first][one.second - 1] = a[two.first][two.second - 1] = '*';
    }
    else 
    {
        a[one.first][two.second] = '*';
        a[two.first][one.second] = '*';
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
            cout << a[i][j]; 
        cout << endl;
    }
}

signed main()
{
    fastIO();
    int T;
    cin >> T;
    while (T--)
        solve();
}
