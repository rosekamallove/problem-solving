#include<iostream>
using namespace std;

int main(){
    int n,count(0); cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if((a and b) or (b and c) or (c and a))
            count++;
    }
    cout<<count<<endl;
}

