#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
bool isPrime[N + 1];

#define endl "\n"
#define deb (x)        cout << #x << ": " << x << endl;
#define tdeb(x, y)     cout << #x << ": " << x << #y << ": " << y << endl;

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int l;
        cin>>l;
        char a[l];

        for(long long int i=0; i<l; i++)
            cin>>a[i];

        double good(0.0);

        for(long long int i=0; i<l; i++)
        {
            if(a[i]=='1')
                good+=1.0;
            if((good >= ((double)(i+1)/2.0)) and good >0.0)
            {
                l = i+1;
                break;
            }
        }

        if(good >= ((double)l / 2.0))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
