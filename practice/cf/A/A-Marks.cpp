#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,count(0); cin>>n>>m;
    vector<string> v(n);
    int arr[n][m];

    for(int i=0; i<n; i++)
        cin>>v[i];

    for(int i=0; i<n; i++){
        string s = v[i];
        for(int j=0; j<m; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; ++i){
        bool wasBest = false;
        for(int j = 0; j < m; ++j){
            bool isBest = true;
            for(int k = 0; k < n; ++k)
                if(arr[k][j] > arr[i][j])
                    isBest = false;
            if(isBest)
                wasBest = true;
        }
        if(wasBest)
            count++;
    }
    cout<<count<<endl;
}
