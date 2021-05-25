#include "bits/stdc++.h" 
using namespace std;
#define int long long

int32_t main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m; cin>>n>>m;
        int count(0);
        for(int i=1; i<n+1; i++)
            for(int j=i+1; j<n+1; j++)
                if((m%i)%j == (m%j)%i)
                    count++;
        cout<<count<<endl;
    }
}
