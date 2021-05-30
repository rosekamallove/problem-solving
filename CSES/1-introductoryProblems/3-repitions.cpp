#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int count(0), ans(0);
    string str; cin>>str;
    char ch('A');

    for(int i=0; i<str.size(); i++){
        if(str[i] == ch){
            ++count;
            ans = max(ans, count);
        }
        else {
            ch = str[i];
            count = 1;
        }
    }
    cout<<ans<<endl;
}
