
#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 12;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int ll
#define fn(i, a, b) for (int i = a; i <= a; i++)
void fileIO();
long long fact[N];

void solve()
{
}

void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        int counter = 0;
        bool is = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (is)
                    continue;
                else
                {
                    counter++;
                    is = 1;
                }
            }
            else
                is = 0;
        }
        cout << counter << endl;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //solve();
    solveT();
    return 0;
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
