#include <iostream>
using namespace std;

#define int long long
double eps = 1e-6;

double multiply(double mid, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
}

int sqrt(int n, int m)
{
    int h(n), l(1);
    int mid(-1);
    while (h - l > 1)
    {
        mid = (h + l) / 2;
        if (multiply((double)mid, m) > n)
        {
            h = mid - 1;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}

signed main()
{
    double n, m;
    cin >> n >> m;
    double l(1), h(n), mid;
    while (h - l > eps)
    {
        mid = (h + l) / 2;
        if (multiply(mid, (int)m) < n)
        {
            l = mid;
        }
        else
        {
            h = mid;
        }
    }
    cout << l << endl;
    cout << sqrt((int)n, (int)m) << endl;
}
