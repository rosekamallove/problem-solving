#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 12;
long long hsh[N];
long long pr[N];

int d2b(int N)
{

    // To store the binary number
    unsigned long long B_Number = 0;
    int cnt = 0;
    while (N != 0)
    {
        int rem = N % 2;
        unsigned long long c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        // Count used to store exponent value
        cnt++;
    }

    return B_Number;
}

int maxProd(int n, int d)
{
    int maxprod = INT_MIN;
    int w = pow(2, d);
    for (int i = 0; i <= w; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if ((i ^ j) == n)
            {
                maxprod = max(maxprod, i * j);
            }
        }
    }
    return maxprod;
}

void solveT()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int d;
        for (int i = 1; i <= n; i++)
        {
            if ((pow(2, i)) > n)
            {
                d = i;
                break;
            }
        }
        cout << maxProd(n, d) << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //solve();
    solveT();
}
