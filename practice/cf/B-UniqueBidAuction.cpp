#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int arr[n+1];
        vector<int> hsh(n+1);
        vector<int> index(n+1);
        arr[0]=0;
        int ans(-1);

        for(int i=1; i<=n; i++)
        {
            cin>>arr[i];
            hsh[arr[i]]++;
            index[arr[i]] = i;
        }

        for(int i=0; i<=n; i++)
            if(hsh[i] == 1)
            {
                ans = index[i];
                break;
            }

        cout<<ans<<endl;

    }
}

