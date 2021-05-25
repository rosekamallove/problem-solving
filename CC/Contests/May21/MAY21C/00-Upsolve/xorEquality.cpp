#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5 +5;
const int mod = 1e9 + 7;

vector<int> ans(mx);

void pre(){
    ans[1] = 1;
    for(int i = 2; i < mx; i++)
        ans[i] = (ans[i-1]*2)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pre();
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        cout<<ans[n]<<endl;
    }
}
