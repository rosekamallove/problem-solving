#include<iostream>
using namespace std;

void solve(){
    int n,ans(0); cin>>n;
    int arr[n + 1];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        arr[i] = arr[i]*arr[i];
    }
    for(int i=0; i<n; i++){
        if(i == 0 or i%2 == 0){
            ans += arr[n - i];
        } else {
            ans -= arr[n - i];
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}

