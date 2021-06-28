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
    int n; read(n);
    char s[n];
    int cnto(0), cntz(0);
    for(int i=0; i<n; i++){
        cin>>s[i];
        if(s[i] == '1'){
            cnto++;
        } else {
            cntz++;
        }
    }
    if(n == 1){
        if(s[0] == '0'){
            cout<<"BOB"<<endl;
            return;
        } else {
            cout<<"DRAW"<<endl;
            return;
        }
    }
    if(not(cntz%2)){
        cout<<"BOB"<<endl;
    } else {
        if(cntz == 1){
            cout<<"BOB"<<endl;
        } else {
            cout<<"ALICE"<<endl;
        }
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

