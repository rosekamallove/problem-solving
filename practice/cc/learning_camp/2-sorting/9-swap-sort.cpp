#include "bits/stdc++.h"
using namespace std; template <typename... T> void read(T &...args) { ((cin >> args), ...); } template <typename T> void readContainer(T &t) { for (auto &e : t) { read(e); } } template<typename T> void _print(T n) { cerr << n; } template<typename T> void _print(vector<T> v) { cerr << "[ "; for (auto val : v) { cerr << val; cerr << ' '; } cerr << "]"; } template <class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; } template <class T> void _print(set <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; } template <class T> void _print(multiset <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; } template <class T, class V> void _print(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

#define int long long
#define endl "\n"

#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ins insert

#ifndef ONLINE_JUDGE
#define deb(x) cerr<<#x<<" -> "; _print(x); cerr<<endl;
#else
#define deb(x)
#endif

bool sorted(vector<int> v) {
    for(int i=0; i<sz(v) - 1; i++)
        if(v[i] > v[i + 1]) return 0;
    return 1;
}

int T(1);
void testCase() {
    int n; cin>>n;
    vector<int> v(n); readContainer(v);

    vector< pair<int, int> > idx;

    for(int i=0; i<n; i++) {
        for(int j=i + 1 ; j<n; j++) {
            if(v[i] > v[j]) {
                swap(v[i], v[j]);
                idx.pb(mp(i, j));
                if(sorted(v)) break;
            }
        }
    }
    cout<<sz(idx)<<endl;
    for(auto x : idx) {
        cout<<x.first<<' '<<x.second<<' ';
    }
    cout<<endl;
}


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

#ifndef ONLINE_JUDGE
    freopen(".deb.txt", "w", stderr);
#endif

//    cin >> T;
    while (T--) {
        testCase();
        cerr<<endl;
    }
}

