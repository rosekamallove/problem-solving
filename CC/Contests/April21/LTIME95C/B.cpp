#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
bool isPrime[N + 1];

#define int long long
#define endl "\n"
#define deb (x)        cout << #x << ": " << x << endl;
#define tdeb(x, y)     cout << #x << ": " << x << #y << ": " << y << endl;

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int anu(0), sar(0);
        string q = "EQUINOX";
        for(int i=0; i<n; i++)
        {
            string s; cin>>s;
            if(s[0] == 'E')
                sar++;
            else if(s[0] == 'E')
                sar++;
            else if(s[0] == 'Q')
                sar++;
            else if(s[0] == 'U')
                sar++;
            else if(s[0] == 'I')
                sar++;
            else if(s[0] == 'N')
                sar++;
            else if(s[0] == 'O')
                sar++;
            else if(s[0] == 'X')
                sar++;
            else
                anu++;
        }
        if(sar*a > anu*b)
            cout<<"SARTHAK"<<endl;
        else if(anu*b > sar*a)
            cout<<"ANURADHA"<<endl;
        else if(anu*b == sar*a)
            cout<<"DRAW"<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}

void readVect(vector<int> v) 
{
    int x; cin>>x;
    v.push_back(x);
}

int Power(int x, int n, int M)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) //n is even
        return Power((x * x) % M, n / 2, M);
    else //n is odd
        return (x * Power((x * x) % M, (n - 1) / 2, M)) % M;
}

void sieve()
{
    for (int i = 0; i <= N; ++i)
        isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N; ++i)
        if (isPrime[i] == true)
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
}

void modularAirthematic()
{
    /*
     * (a+b)%c == (a%c + b%c)%c
     * (a*b)%c == ((a%c) * (b%c))%c
     * (a-b)%c == ((a%c) - (b%c) + c)%c
     * (a/b)%c == ((a%c) * (b^-1 %c))%c
     */
}
