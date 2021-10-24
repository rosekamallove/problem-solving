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

int T(1);
void fastIO();
template<typename T>        void _print(T n);
template <class T, class V> void _print(pair <T, V> p);
template <class T>          void _print(vector <T> v);
template <class T>          void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T>          void _print(multiset <T> v);
template<typename... T>     void read(T&... args);
template<typename... T>     void write(string delimiter, T &&...args);
template<typename T>        void readContainer(T &t);
template<typename T>        void writeContainer(string delimiter, T &t);
//----------------------------------------------------------------------------------------------------//

void testCase() {
    string s; cin>>s;
    int n = s.size(), l(0), r(0);
    bool noOneFound = 1, noZeroesFound = 1;
    for(int i=0; i<n;i++){
        if(s[i] == '1'){
            noOneFound = 0;
        } else if(s[i] == '0'){
            noZeroesFound = 0;
        }
    }
    if(noOneFound){
        cout<<"NO"<<endl;
        return;
    } else if(noZeroesFound){
        cout<<"YES"<<endl;
        return;
    }

    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            l = i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(s[i] == '1'){
            r = i;
            break;
        }
    }

    for(int i=l; i<=r; i++){
        if(s[i] == '0'){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}


signed main() {
    /*--------------------------------------*/
    fastIO();
#ifndef ONLINE_JUDGE
    freopen(".deb.txt", "w", stderr);
#endif
    /*--------------------------------------*/
    cin >> T;
    while (T--) {
        cerr<<"<------TC------>"<<endl;
        testCase();
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}


//----------------------------------------------------------------------------------------------------//
template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(string delimiter, T &&...args) {
    ((cout << args << delimiter), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}

template <typename T>
void writeContainer(string delimiter, T &t) {
    for (const auto &e : t) {
        write(delimiter, e);
    }
    write("\n");
}

template<typename T>
void _print(T n) {
    cerr << n;
}

template<typename T>
void _print(vector<T> v) {
    cerr << "[ ";
    for (auto val : v) {
        cerr << val;
        cerr << ' ';
    }
    cerr << "]";
}
template <class T, class V>
void _print(pair <T, V> p) {
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}

template <class T>
void _print(set <T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T> void _print(multiset <T> v) {
    cerr << "[ ";
    for (T i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ ";
    for (auto i : v) {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

