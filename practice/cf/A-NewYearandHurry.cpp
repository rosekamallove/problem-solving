#include<iostream>
using namespace std;

int main(){
    int n, k; cin>>n>>k;
    int total(0), ans(-1);
    for(int i=1; i<=n; i++){
        total += 5*i;
        if(total+k > 4*60){
            ans = i-1;
            break;
        } 
        else
            ans = i;
    }
    cout<<ans<<endl;
}

