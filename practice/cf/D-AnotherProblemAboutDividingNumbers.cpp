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

vector<bool> isPrime(50000, 1);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p < isPrime.size(); p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i < isPrime.size(); i += p) {
                isPrime[i] = false;
            }
        }
    }
}

vector<int> prime;
void pre() {
    sieve();
    for(int i = 2; i < isPrime.size(); i++) {
        if(isPrime[i]) {
            prime.push_back(i);
        }
    }
}


void solve() {
    int a,b,k;
    read(a,b,k);
    int mxSteps(0), mnSteps(0);

    // -- Counting MinSteps -------------------------------------------------------
    if(a == b) {
        mnSteps = 0;
    } else if(__gcd(a,b) == a || __gcd(a,b)==b) {
        mnSteps = 1;
    } else {
        mnSteps = 2;
    }

    // -- Counting No. of Prime Factors i.e, MaxSteps -----------------------------
    // -- For 'a' -----------
    for(int i : prime) {
        if(i * i > a) {
            break;
        }
        while(a%i == 0) {
            mxSteps++;
            a /= i;
        }
    }
    if(a > 1) {
        mxSteps++;
    }
    // -- For 'b' -----------
    for(int i : prime) {
        if(i * i > b) {
            break;
        }
        while(b%i == 0) {
            mxSteps++;
            b /= i;
        }
    }
    if(b > 1) {
        mxSteps++;
    }

    if(k >= mnSteps and k <= mxSteps and k == 1 and mnSteps == 1) {
        cout<<"YES"<<endl;
        return;
    }
    if(k >= mnSteps and k <= mxSteps and k != 1) {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
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
    pre();
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

