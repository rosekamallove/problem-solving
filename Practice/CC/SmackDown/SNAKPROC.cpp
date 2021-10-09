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
//
void crapSolution() {
    int n; string s;
    cin>>n>>s;
    bool wasH = 0;
    bool firstH = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'H'){
            if(wasH){
                cout<<"Invalid"<<endl;
                return;
            }
            wasH = 1;
            if(!firstH){
                firstH = 1;
            }
        } else if(s[i] == 'T'){
            if(!firstH){
                cout<<"Invalid"<<endl;
                return;
            }
            if(wasH){
                wasH = 0;
            }
        }
    }
    if(s[n-1] == 'H'){
        cout<<"Invalid"<<endl;
        return;
    }
    cout<<"Valid"<<endl;
}

void testCase() {
    int n; string c;
    cin>>n>>c;
    string s;
    for(int i=0; i<n; i++){
        if(c[i] != '.'){
            s += c[i];
        }
    }
    if(s.size() % 2){
        cout<<"Invalid"<<endl;
        return;
    } 
    for(int i=0; i<s.size(); i++){
        if(i % 2){
            if(s[i] != 'T'){
                cout<<"Invalid"<<endl;
                return;
            }
        } else if(s[i] != 'H'){
                cout<<"Invalid"<<endl;
                return;
        }
    }
    cout<<"Valid"<<endl;
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

