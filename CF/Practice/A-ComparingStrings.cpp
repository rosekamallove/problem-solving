#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,g; cin>>s>>g;
    int r(0),m(0),count(0);

    if(s.size() != g.size()){
        cout<<"NO"<<endl;
        return 0;
    }
    if(s.size() == g.size()){
        for(int i=0; i<s.size(); i++){
            if(s[i] != g[i]){
                count++;
                if(count == 1)
                    r = i;
                else if(count == 2)
                    m = i;
            }
        }
    }
    if(count > 2 or count == 1){
        cout<<"NO"<<endl;
        return 0;
    }
    swap(s[r], s[m]);
    if(s == g){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}

