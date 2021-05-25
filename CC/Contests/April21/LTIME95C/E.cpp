#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, w, wr;
        cin>>n>>w>>wr;

        vector<int> v(n);

        for(int i=0; i<n; i++)
            cin>>v[i];

        sort(v.begin(), v.end(), greater<int>());
        int sum(wr);
        //cout<<sum<<endl;

        for(int i=0; i<n-1;)
        {
            if(sum>=w)
                break;
            if(v[i]==v[i+1])
            {
                //cout<<"i => "<<i<<"v[i] => "<<v[i]<<"v[i+1] => "<<v[i+1]<<endl;
                sum+=v[i]*2;
                i+=2;
                //cout<<"sum => "<<sum<<endl;
            }
            else
                i++;
        }

        if(sum>=w)
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
