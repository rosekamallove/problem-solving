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
bool isStringPresentInVector(vector<string> v, string s) {
    int temp(0);
    for(int i=0; i<s.size(); i++) {
        if(v[i] == s) {
            temp++;
        }
    }
    return !(temp == 1);
}

void crapSolutin() {
    int n;
    cin>>n;
    cout<<n<<endl;
    float bigTime = 0;

    vector<string> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    for(int k=0; k<n; k++) {
        string s = v[k];
        cout<<s<<endl;
        float time(0.2);

        for(int i=1; i<s.size(); i++) {
            if(s[i] == 'd' or s[i] == 'f') {
                if(s[i - 1] == 'd' or s[i - 1] == 'f') {
                    time += 0.4;
                } else {
                    time += 0.2;
                }
            } else {
                if(s[i - 1] == 'j' or s[i - 1] == 'k') {
                    time += 0.4;
                } else {
                    time += 0.2;
                }
            }
        }
        deb(time);
        if(isStringPresentInVector(v, s)) {
            deb(time/2);
            bigTime += time/2;
        } else {
            bigTime += time;
        }
    }
    cout<<bigTime * 10<<endl;
}

void testCase() {
    int ans = 0,temp,flag, n;
    string s;
    cin>>n;
    unordered_map <string,int> umap;
    ans = 0;
    for(int i=0; i<n; i++) {
        temp = 0;
        flag = 1;
        cin>>s;
        if(umap.find(s)!=umap.end()) {
            ans += umap[s]/2;
            continue;
        }
        temp += 2;
        if(s[0]=='d' || s[0]=='f') flag=0;
        for(int i=1; i<s.length(); i++) {
            if((s[i]=='d' || s[i]=='f')) {
                if(flag == 0) temp += 4;
                else temp += 2;
                flag = 0;
            }
            else {
                if(flag == 0) temp += 2;
                else temp += 4;
                flag = 1;
            }
        }
        umap[s] = temp;
        ans += temp;
    }
    cout<<ans<<endl;
    umap.clear();
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

