#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int toFind; cin>>toFind;
    int h(0), l(n-1), ans(-1);

    while(h - l > 1){
        //int mid(h + (h-l)/2);
        int mid((h+l)/2);
        if(v[mid] < toFind){
            l = mid + 1;
        } 
        else {
            h = mid;
            //ans = mid;
        }
        //if (v[mid] > toFind){
        //    h = mid - 1;
        //}
    }
    if(v[l] == toFind){
        cout<<l<<endl;
    }else if(v[h] == toFind){
        cout<<h<<endl;
    }else{
        cout<<-1<<endl;
    }
    //cout<<ans<<endl;
}

