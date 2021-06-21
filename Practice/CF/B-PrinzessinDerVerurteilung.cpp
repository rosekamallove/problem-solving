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

void solve(){
    int n;
    string s;
    read(n,s);

    vector<int> count(26, 0); /* simple hash array */
    for(int i=0; i<n; i++){
        count[s[i] - 'a'] = 1;
        deb(s[i] - 'a');
    }

    /* Iterating from a => z */
    for(int i=0; i<26; i++){
        if(count[i] == 0){
            cout<<(char)('a' + i)<<endl;
            return;
        }
    }

    {// A new thing that i Learned about scoping.

        set<string> st; /* Stores all the 2 length substring of the string s */
        for(int i=0; i<n-1; i++){
            string temp = "";
            temp += s[i];
            temp += s[i+1];
            deb(temp);
            st.insert(temp);
        }
        deb(st);
        /* Iterating for all the two digit substrings aa => az */
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                string temp = "";
                temp += (char)('a' + i);
                temp += (char)('a' + j);
                deb(temp);
                if(st.find(temp) == st.end()){
                    cout<<temp<<endl;
                    return;
                }
            }
        }
    }
    {
        /* For substring of length 3 */
        set<string> st;
        for(int i=0; i<n-2; i++){
            string temp = "";
            temp += s[i];
            temp += s[i + 1];
            temp += s[i + 2];
            st.insert(temp);
        }
        /* Iterating for all the 3 length substring but with the first char fixed to 'a' */
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                string temp = "a";
                temp += (char)('a' + i);
                temp += (char)('a' + j);
                if(st.find(temp) == st.end()){
                    cout<<temp<<endl;
                    return;
                }
            }
        }
    }
}

signed main(){
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
    while (T--){
        solve();
    }
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
    } cerr << "]";}

template <class T, class V> void _print(map <T, V> v){
    cerr << "[ "; 
    for (auto i : v) {
        _print(i); 
        cerr << " ";
    } 
    cerr << "]";
}

