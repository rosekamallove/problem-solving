#include <iostream>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x, y) cout << #x << ": " << x << " " << #y << ": " << y << endl;

float round(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        float v, k1, k2, k3;
        cin >> k1 >> k2 >> k3 >> v;
        float f = 100 / (v * k1 * k2 * k3);
        float cmpr = 9.58;
        f = round(f);

        if (f > cmpr)
            cout << "NO" << endl;
        else if (cmpr - f == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solveT();
}