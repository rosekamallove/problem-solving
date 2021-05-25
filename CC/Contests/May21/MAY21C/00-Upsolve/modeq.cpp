#include<bits/stdc++.h>
using namespace std;

void unoptimized(){
    int count(0),n,m; cin>>n>>m;

    for(int i=1; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if((m%i)%j == (m%j)%i)
                count++;

    cout<<count<<endl;
}

/*Optimized*/

const int M = 5e5 +5;
vector<vector<int>> divs(M);

void pre(){
    int i, j;
    for(i=1; i<M; i++){
        for(j=i; j<M; j+=i)
            divs[j].push_back(i);
    }
}

void solve(){
    int n, m, b; cin>>n>>m;
    int res = 0;
    for(b=2; b<=n; b++){
        int x(m-(m%b));
        if(x>0)
            res += lower_bound(divs[x].begin(), divs[x].end(), b) - divs[x].begin();
        else
            res += b-1;
    }
    cout<<res<<endl;
}

int main(){
    pre();
    int T; cin>>T;
    while(T--)
        solve();
}
