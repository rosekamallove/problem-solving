#include<bits/stdc++.h>
using namespace std;

#define int long long

int pow(int x, int y)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return pow(x, y / 2) * pow(x, y / 2);
    else
        return x * pow(x, y / 2) * pow(x, y / 2);
}

signed main(){
    int k,l; cin>>k>>l;
    bool is(0);
    
    int itr(0), i(1);
    while(true){
        itr = pow(k,i);
        if(itr > l)
            break;
        if(itr==l){
            is = 1;
            break;
        }
        i++;
    }
    if(is){
        cout<<"YES"<<endl;
        cout<<i-1<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

