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
    int a,b,c; read(a,b,c);

    /* These are the values of gcd(x,y) with the length c where 1 >= c <= 9 */
    vector<int> minPrime;
	minPrime.push_back(3);
	minPrime.push_back(11);
	minPrime.push_back(101);
	minPrime.push_back(1009);
	minPrime.push_back(10007);
	minPrime.push_back(100003);
	minPrime.push_back(1000003);
	minPrime.push_back(10000019);
	minPrime.push_back(100030001);

    int x(minPrime[c-1]);
    int a1(0), a2(0), size(0);

    while(true){
        
        int temp = x;
        while(temp > 0){
            temp /= 10;
            size++;
        }
        if(size == a){
            a1 = x;
            break;
        } else {
            x = x*2;
            size = 0;
        }
    }
    x = minPrime[c-1];
    size = 0;
    while(true){
        
        int temp = x;
        while(temp > 0){
            temp /= 10;
            size++;
        }
        if(size == b){
            a2 = x;
            break;
        } else {
            x = x*3;
            size = 0;
        }
    }
    cout<<a1<<' '<<a2<<endl;
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

