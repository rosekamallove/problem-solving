#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x,y) cout << #x << ": " << x << #y << ": " << y << endl;


int power(int x, unsigned int y)
{
    int res(1);

    while (y > 0)
    {
        if (y & 1)
            res = res*x;

        y = y>>1;  
        x = x*x; 
    }
    return res;
}

void solve()
{
    int n,m,k; cin>>n>>m>>k;

    double arr[n+1][m+1];

    for(int i(0); i<=n; i++)
        for(int j(0); j<=m; j++)
        {
            if(i==0 or j==0)
                arr[i][j] = 0;
            else
                cin>>arr[i][j];
        }

    for(int i(0); i<=n; i++)
    {
        double prefix(0);
        for(int j(0); j<=m; j++)
        {
            arr[i][j] = arr[i][j] + prefix;
            prefix = arr[i][j];
        }
    }
    for(int j(0); j<=m; j++)
    {
        double prefix(0);
        for(int i(0); i<=n; i++)
        {
            arr[i][j] = arr[i][j] + prefix;
            prefix = arr[i][j];
        }
    }

    int count(0);

    int minIdx(min(n,m));
    for(int size(1); size<=minIdx; size++)
    {
        for(int i(size); i<=n; i++)
        {
            for(int j(size); j<=m; j++)
            {
                int sum(arr[i][j]+arr[i-size][j-size]-arr[i][j-size]-arr[i-size][j]);
                //if((sum/power(size,2))>=k)
                if(sum/(size*size)>=k)
                    count++;
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
