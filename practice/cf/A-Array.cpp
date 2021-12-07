#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v1,v2,v3;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x < 0){
            v1.push_back(x);
        }
        if(x > 0){
            v2.push_back(x);
        }
        if(x == 0){
            v3.push_back(x);
        }
    }

    if(v2.size() == 0){
        for(int i=0; i<2; i++){
            v2.push_back(v1.back()), v1.pop_back();
        }
    }
    if(v1.size()%2 ==  0){
        v3.push_back(v1.back());
        v1.pop_back();
    }


    cout<<v1.size()<<' ';
    for(int x : v1){
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<v2.size()<<' ';
    for(int x : v2){
        cout<<x<<' ';
    }
    cout<<endl;
    cout<<v3.size()<<' ';
    for(int x : v3){
        cout<<x<<' ';
    }
    cout<<endl;
}
