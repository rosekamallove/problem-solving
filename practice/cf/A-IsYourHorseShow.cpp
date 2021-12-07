#include<bits/stdc++.h>
using namespace std;

int main(){
    int n(4);
    set<int> st;
    while(n--){
        int a; cin>>a;
        st.insert(a);
    }
    cout<<4 - st.size()<<endl;
}

