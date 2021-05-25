#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define deb(x) cout << #x << ": " << x << endl;
#define tdeb(x, y) cout << #x << ": " << x << #y << ": " << y << endl;
#define rep(i, n) for (int i(0); i < n; i++)
#define rip(i, n) for (int i(1); i <= n; i++)
#define rap(i, a, n) for (int i(a); i < n; i++)

void readArr(int arr[], int n) {rep(i,n) cin>>arr[i];}
void printArr(int arr[], int n) {rep(i,n) cout<<arr[i]<<' '; cout<<endl;}

void solve()
{
    int n,m; cin>>n>>m;
    int time[n], wa[m];
    readArr(time, n);
    readArr(wa, m);

    sort(time, time+n);
    sort(wa, wa+m);

    int v(2*time[0]);

    v = max(v, time[n-1]);

    if(wa[0] <= v)
        v = -1;

    cout<<v<<endl;

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
