#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl "\n"
#define all(x) x.begin() x.end()

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " ++> "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

void fastIO();
template<typename T>        void _print(T n);
template <class T>          void _print(vector <T> v);
template<typename... T>     void read(T&... args);
template<typename T>        void readContainer(T &t);
//----------------------------------------------------------------------------------------------------//

void solve() {
    string s;
    read(s);
    int ans(0),countQ(0), n(s.size()), startIdx(0), endIdx(0);
    ans += n;
    char start(' '), end(' ');

    for(int i=0; i<n; i++){
        for(int j=i + 1; i<n; i++){
            if(s[j] == '?' and j == i+1 ){
                continue;
            }
            if(s[j] == '?'){
                ans += j - i;
                continue;
            }
            if(s[j] == s[i]){
                ans += j - i;
                continue;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(i >= 1) {
            if(s[i] == '?') {
                if(s[i-1] != '?') {
                    start = s[i - 1];
                    startIdx = i - 1;
                }
                countQ++;
            } else {
                if(s[i-1] == '?') {
                    end = s[i];
                    endIdx = i;
                    if((start == end and countQ%2 != 0) or (start != end and countQ%2 == 0)) {
                        ans += endIdx - startIdx;
                    }
                }
                endIdx = 0;
                startIdx = 0;
                start = ' ';
                end = ' ';
                countQ = 0;
            }
        }
    }
    cout<<ans<<endl;
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
        solve();
    }

    cerr<<endl;
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}


//----------------------------------------------------------------------------------------------------//
template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template<typename T>
void _print(T n) {
    cerr << n;
}

template<typename T>
void _print(vector<T> v) {
    cerr << '[';
    for (auto val : v) {
        cerr << val;
        cerr << ' ';
    }
    cerr << ']';
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

