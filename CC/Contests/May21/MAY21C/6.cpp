#include "bits/stdc++.h" 
using namespace std;

#define fastIO()       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define endl "\n"
#define mod %

#define testCase       cout<<"<<<<<<<<<<<<<<<=TestCase=>>>>>>>>>>>>>>>>>>"<<endl;
#ifndef ONLINE_JUDGE
#define tdeb(x,y)      cout <<'('<< #x<<','<<#y<<") ++> "; print(x,y)
#define deb(x)         cout << #x << " ++> "; print(x)
#else
#define tdeb(x,y)
#define deb(x)
#endif

//COlors:
#define RESET       "\033[0m"
#define BLACK       "\033[30m"             /* Black */
#define RED         "\033[31m"             /* Red */
#define GREEN       "\033[32m"             /* Green */
#define YELLOW      "\033[33m"             /* Yellow */
#define BLUE        "\033[34m"             /* Blue */
#define MAGENTA     "\033[35m"             /* Magenta */
#define CYAN        "\033[36m"             /* Cyan */
#define WHITE       "\033[37m"             /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define rep(i,n)       for (int i(0); i<n ;  i++)
#define rip(i,n)       for (int i(1); i<=n;  i++)
#define rap(i,a,n)     for (int i(a); i<n ;  i++)
template<typename T>   void print(vector<T> v);
template<typename T>   void print(T n);
template<typename T,   typename Tt> void print(T n, Tt m);
//----------------------------------------------------------------------------------------------------//
//
void unOptimised()
{
    int n, m; cin>>n>>m;
    int count(0);
    rap(i,1,n+1)
        rap(j,i+1,n+1)
            if(j%i==0)
                count++;
    cout<<count<<endl;
}

void testing()
{
    rap(f,2,20)
    {
        int m(f);
        cout<<YELLOW<<"::::::::For m => "<<m<<RESET<<endl;

        for(int n=1; n<100; n++)
        {
            rap(i,1,n+1)
            {
                rap(j,i+1,n+1)
                {
                    int a(i), b(j);

                    cout<<BOLDCYAN<<'('<<a<<','<<b<<')'<<RESET;
                    if((m%a)%b == (m%b)%a)
                    {
                        cout<<GREEN<<"   ++> Condition Satisfied"<<RESET<<endl;;
                        if(b%a==0)
                           cout<<BOLDGREEN<<"             b is divisible by a"<<RESET<<endl;
                    }
                    else
                    {
                        cout<<RED<<"   ++> Condition UnSatisfied"<<RESET<<endl;
                        if(b%a==0)
                           cout<<BOLDRED<<"               b is not  divisible by a"<<RESET<<endl;
                    }
                }
            }
        }

    }
}

void solve()
{
    int n, m; cin>>n>>m;
    int count(0);
    int arr[n+1];

    rep(i, n+1)
        arr[i] = 1;

    for(int i=2; i<=n; i++)
    {
        count += arr[m%i];
        for(int j=m%i; j<n; j+=i)
            arr[j]++;
    }
    cout<<count<<endl;
}

signed main()
{
    fastIO();
    int T;
    cin >> T;
    while (T--)
        solve();
}

template<typename T, typename Tt> void print(T n, Tt m){
    cout<<'{'<<n<<','<<m<<'}'<<endl;
}

template<typename T> void print(T n){
    cout<<n<<endl;
}

template<typename T> void print(vector<T> v) {
    cout<<'[';
    for(auto val : v){
        cout<<val;
        cout<<' ';
    }
    cout<<']'<<endl;
}
