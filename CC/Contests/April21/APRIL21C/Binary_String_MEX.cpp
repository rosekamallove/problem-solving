#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;

int d2b(int N)
{
    int B_Number = 0;
    int cnt = 0;
    while (N != 0)
    {
        int rem = N % 2;
        int c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        cnt++;
    }

    return B_Number;
}

bool isSub(string t, string s)
{
    if (s == t)
        return true;
    int n = s.size();
    int m = t.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[j] == s[i])
            j++;
        if (j == t.size())
            return true;
    }
    return false;
}

bool isSubSequence(string str1, string str2, int m, int n)
{

    // Base Cases
    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);

    return isSubSequence(str1, str2, m, n - 1);
}

void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans("");
        int i(0);
        while (1)
        {
            int tempb = d2b(i);
            string substr = to_string(tempb);
            // int N = substr.size();
            // int M = s.size();
            if (!(isSub(substr, s)))
            {
                ans = substr;
                break;
            }
            i++;
        }
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solveT();
}
