#include<iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<int> a, vector<int> b) {
    vector<int> ans;
    int i(0), j(0), n(a.size()), m(b.size());

    while(i < n and j < m) {
        if(a[i] < b[j]) {
            i++;
        } else if(a[i] > b[j]) {
            j++;
        } else {
            ans.push_back(a[i++]);
            j++;
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int &x : a) cin>>x;
    for(int &x : b) cin>>x;

    a = solve(a, b);

    for(int &x : a) cout<<x<<' ';
    cout<<endl;

}
