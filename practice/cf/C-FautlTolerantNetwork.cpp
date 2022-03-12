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
    int n; cin>>n;
    vector<int> a(n), b(n);
    readContainer(a);
    readContainer(b);

    vector<int> ans;

    int mina(INT_MAX), minb(INT_MAX);
    for(int i=1; i<n - 1; i++) {
        mina = min(a[i], mina);
        minb = min(b[i], minb);
    }
    
    {// Case 1
        int temp = abs(a[0] - b[0]) + abs(a[n-1] - b[n - 1]);
        ans.push_back(temp);
    }

    {//Case 2
        int temp = abs(a[0] - b[0]);
        temp += abs(a[n - 1] - minb);
        temp += abs(mina - b[n - 1]);
        ans.push_back(temp);
    }

    {// Case 3
        int temp = abs(a[n-1] - b[n - 1]);
        temp += abs(a[0] - minb);
        temp += abs(mina - b[0]);
        ans.push_back(temp);
    }

    {// Case 4
        int temp = abs(a[0] - minb) + abs(a[n - 1] - minb);
        temp += abs(mina - b[0]) + abs(mina - b[n - 1]);
        ans.push_back(temp);
    }

    {// Case 5
        int temp = abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]);
        ans.push_back(temp);
    }

    {// Case 6
        int temp = abs(a[0] - b[n - 1]);
        temp += abs(mina - b[0]);
        temp += abs(a[n - 1] - minb);
        ans.push_back(temp);
    }

    {// Case 7
        int temp = abs(a[n - 1] - b[0]);
        temp += abs(a[0] - minb);
        temp += abs(mina - b[n - 1]);
        ans.push_back(temp);
    }
    int result(INT_MAX);

    for(auto &x : ans) {
        result = min(result, x);
    }
    cout<<result<<endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*--------------------------------------*/
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

