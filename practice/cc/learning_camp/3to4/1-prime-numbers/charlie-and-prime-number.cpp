#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6;
vector<char> isPrime(N+1, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}

void solve() {

    int arr[N];

    int t; cin>>t;
    while(t--) {
        int m, sum(0), n; cin>>m>>n;
        for(int i=m; i<=n; i++) {
            if(isPrime[i])
                sum += i;
        }
        cout<<sum<<endl;
    }
}


signed main(){
    int t; cin>>t;
    sieve();
    solve();
}

