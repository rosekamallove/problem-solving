#include "bits/stdc++.h"
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int k; cin>>k;
        int n = 2*k;
        int ans(0);

        for(int i=1; i<=n; i++)
            ans += __gcd((k+i*i), k+((i+1)*(i+1)));
        cout<<ans<<endl;
    }
}

