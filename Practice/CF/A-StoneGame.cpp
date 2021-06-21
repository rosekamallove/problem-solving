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

void solve() {
    int n; read(n);
    vector<int> v(n);
    readContainer(v);
    int maxPos = max_element(v.begin(), v.end()) - v.begin();
    int minPos = min_element(v.begin(), v.end()) - v.begin();
    cout << min({
            max(maxPos, minPos) + 1,
            (n - 1) - min(maxPos, minPos) + 1,
            (n - 1) - maxPos + minPos + 2,
            (n - 1) - minPos + maxPos + 2
    }) << endl;
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

