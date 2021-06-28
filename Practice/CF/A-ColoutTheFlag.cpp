#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl "\n"
#define all(x) x.begin(),x.end()

#ifndef ONLINE_JUDGE
#define deb(x) cerr<<#x<<"=>"; _print(x); cerr<<endl;
#else
#define deb(x)
#endif

void fastIO();
template<typename T>void _print(T n);
template<class T>void _print(vector<T>v);
template<typename... T>void read(T&... args);
template<typename T>void readContainer(T &t);
//----------------------------------------------------------------------------------------------------//

void testCase(/* SampleTestCases!! */) {
    int n,m; read(n,m);
    vector<vector<char>> grid(n+1, vector<char> (m+1));
    vector<vector<char>> grid1 = grid;
    vector<vector<char>> grid2 = grid;
    bool isIt(1);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>grid[i][j];
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            if(grid[i][j] == grid[i-1][j-1]){
                isIt = false;
                break;
            }
        }
    }
    if(isIt){
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        return;
    }
    /*Grid 1*/
    isIt = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid1[i][j] == '.' and (i+j)%2==0){
                grid1[i][j] = 'R';
            } else if(grid1[i][j] == '.' and (i+j)%2!=0){
                grid1[i][j] = 'W';
            }
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            if(grid1[i][j] == grid1[i-1][j-1]){
                isIt = false;
                break;
            }
        }
    }
    if(isIt){
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout<<grid1[i][j];
            }
            cout<<endl;
        }
        return;
    }
    /*Grid 2*/
    isIt = true;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(grid2[i][j] == '.' and (i+j)%2!=0){
                grid2[i][j] = 'R';
            } else if(grid2[i][j] == '.' and (i+j)%2 == 0){
                grid2[i][j] = 'W';
            }
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            if(grid2[i][j] == grid2[i-1][j-1]){
                isIt = false;
                break;
            }
        }
    }
    if(isIt){
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout<<grid2[i][j];
            }
            cout<<endl;
        }
        return;
    }
}

signed main() {
    /*--------------------------------------*/
    fastIO();
#ifndef ONLINE_JUDGE
    freopen(".deb.txt", "w", stderr);
#endif
    /*--------------------------------------*/
    int T(1);
    cin >> T;
    while (T--) {
        cerr<<endl;
        testCase();
    }
    cerr<<endl;
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}


//----------------------------------------------------------------------------------------------------//
template <typename... T>void read(T &...args) {
    ((cin>>args),...);
}
template<typename T>void readContainer(T&t) {
    for(auto&e:t) {
        read(e);
    }
}
template<typename T>void _print(T n) {
    cerr << n;
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

template<typename T>void _print(vector<T> v) {
    cerr << '[';
    for (auto val : v) {
        cerr << val;
        cerr << ' ';
    }
    cerr << ']';
}

