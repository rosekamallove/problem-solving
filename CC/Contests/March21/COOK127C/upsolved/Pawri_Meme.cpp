#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solveT()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        size_t idx = 0;
        while (1)
        {
            idx = str.find("party", idx);
            if (idx == -1)
                break;

            str.replace(idx, 5, "pawri");
            idx += 5;
        }
        cout << str << endl;
    }
}

void altSolve()
{
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        size_t idx = s.size();
      //The idea is to check all the substrs of length 5

        for(int i(0); i+4<idx; i++)
        {
            if(s.substr(i,5)=="party")
            {
                s[i+2]='w';
                s[i+3]='r';
                s[i+4]='i';
            }
        }
        cout<<s<<endl;
    }
}

void solve()
{
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    altSolve();
    //solve();
}
