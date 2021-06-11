#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, step; cin>>n;
    step = n/5;
    if(n%5==0){
        cout<<step<<endl;
    } else {
        cout<<step + 1<<endl;
    }
}

