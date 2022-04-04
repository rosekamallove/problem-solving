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

struct point {
    int weight, position, id;
};

int T(1);
#define CIN cin>>T;
void testCase() {
    int n, m; cin>>n>>m;
    vector<point> points(m);
    for(int i=0; i<m; i++) {
        cin>>points[i].position>>points[i].weight;
        points[i].id = i + 1;
    }

    sort(all(points), 
        [] (point a, point b) {
            return a.weight < b.weight;
        }
    );

    int sum(0);
    for(int i=0; i<m; i++) {
        if(i < 2*n) sum += points[i].weight;
        else points.pop_back();
    }

    sort(all(points), 
        [] (point a, point b) {
            return a.position < b.position;
        }
    );

    cout<<sum<<endl;

    for(int i=0; i<n; i++) {
        cout<<points[i].id<<' '<<points[2*n - i - 1].id<<endl;
    }
}


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

#ifndef ONLINE_JUDGE
    freopen(".deb.txt", "w", stderr);
#endif

    CIN
    while (T--) {
        testCase();
        cerr<<endl;
    }
}

