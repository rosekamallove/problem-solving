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
    int l, r; cin>>l>>r;
    /*
     * Brute force would be to generate all the sums
     * then purge the repeating elements
     * O(n*n)
     */

    /*
     * take the lower limit of sum i.e  l + l
     * take the uppper limit of sum i.e r + r
     * all the numbers between these limits will be present in the sum array,
     *
     * this can be proved by the following:
     * S + 1 and S - 1 can be obtained by incrementing or decrementing x or y
     * but if we cannot increment or decrement, it means we've reached the range end points
     */
    cout<<(r*2 - l*2) + 1<<endl;

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

