#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, m, k;
        cin >> a >> m >> k;
        if (m == 1)
        {
            long long ans = 0;
            for (int i = 1; i <= a; i++)
            {
                ans = ans ^ (i + 1 + k);
            }
            cout << ans << endl;
        }
        else if (a == 1)
        {
            long long ans = 0;
            for (int i = 1; i <= m; i++)
            {
                ans = ans ^ (i + 1 + k);
            }
            cout << ans << endl;
        }
        else if (a % 2 == 0)
        {
            long long int ans = 0;

            for (int i = 1; i <= a; i += 2)
            {
                ans = ans ^ (i + 1 + k);
            }

            for (int i = 2; i <= a; i += 2)
            {
                ans = ans ^ (i + m + k);
            }
            cout << ans << endl;
        }
        else
        {
            long long int ans = 0;

            for (int i = 1; i < a; i += 2)
            {
                ans = ans ^ (i + 1 + k);
            }

            for (int i = 2; i <= a; i += 2)
            {
                ans = ans ^ (i + m + k);
            }

            for (int i = 1; i <= m; i++)
            {
                ans = ans ^ (i + a + k);
            }

            cout << ans << endl;
        }
    }
    return 0;
}