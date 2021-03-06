#include "bits/stdc++.h"
using namespace std;

#define int long long
#define endl "\n"

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x << " ++> "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

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

char v [1000003];

void solve() {
    int n;
    cin>>n;
    cin>>(v+1);
    int i,j;
    int cnt=0;
    for(i=1;i<=n;++i)
        if(v[i]=='*')
            ++cnt;
    cnt=(cnt+1)/2;
    int s=0;
    for(i=1;i<=n;++i)
        if(v[i]=='*'){
            ++s;
            if(s==cnt)
                break;
        }
    cnt=0;
    long long rz=0;
    for(j=i;j>=1;--j){
        if(v[j]=='.')
            ++cnt;
        else
            rz+=cnt;
    }
    cnt=0;
    for(j=i+1;j<=n;++j)
        if(v[j]=='.')
            ++cnt;
        else
            rz+=cnt;
    cout<<rz<<'\n';
}

signed main() {
    /**************************************/
#ifndef ONLINE_JUDGE
    freopen(".deb.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /**************************************/
    int T;
    cin >> T;
    while (T--) {
        solve();
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
    cerr << '[';
    for (auto val : v) {
        cerr << val;
        cerr << ' ';
    }
    cerr << ']';
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

