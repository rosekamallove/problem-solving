#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> a, vector<int> b) {
    vector<int> ans;
    int i(0), j(0), n(a.size()), m(b.size());

    while(i < n and j < m) {
        if(a[i] < b[j]) {
            ans.push_back(a[i++]);
        } else if(a[i] > b[j]) {
            ans.push_back(b[j++]);
        } else {
            ans.push_back(a[i++]);
            j++;
        }
    }
    while(i < n) ans.push_back(a[i++]);
    while(j < m) ans.push_back(b[j++]);

    return ans.size();
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int &x : a) cin>>x;
    for(int &x : b) cin>>x;
    cout<<solve(a, b)<<endl;
}

