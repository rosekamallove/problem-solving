#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x,y) cout << #x << ": " << x << #y << ": " << y << endl;

void solve()
{
    int n,m,k; cin>>n>>m>>k;
    int arr[n+1][m+1];

    memset(arr,0,sizeof(arr));

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>arr[i][j];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            arr[i][j] += arr[i][j-1];

    for(int j=1; j<=m; j++)
        for(int i=1; i<=n; i++)
            arr[i][j] += arr[i-1][j];

    int count = 0;

    for(int order = 1; order<=n; order++)
    {
        for(int i=1; i<=n-order+1; i++)
        {
            int low = 1;
            int high = m-order+1;
            int mid;
            int p;
            int flag=0;

            while(low<=high)
            {
                mid = (high+low)/2;
                int sum = arr[i+order-1][mid+order-1] - arr[i+order-1][mid-1] - arr[i-1][mid+order-1] + arr[i-1][mid-1];

                if(sum>=k*order*order)
                {
                    high = mid-1;
                    p = mid;
                    flag = 1;
                }
                else 
                    low = mid + 1;
            }
            if(flag==1)
            {
                count+=(m-order-p+2);
            }
        }
    }
    cout<<count<<endl;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

        int t; cin>>t;
        while(t--)
	        solve();
}
