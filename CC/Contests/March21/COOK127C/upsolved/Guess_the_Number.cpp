#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
void solveT()
{
    for (int i = 1; i < 1e6; i++)
    {//all the perfect squares have odd number of factors
        if (sqrt(i) == (int)sqrt(i))
        {
            v.push_back(i);
        }
        //cout<<v.size()<<endl; -> Gives output 999
    }
    int t;
    cin >> t;
    while (t--)
    {
        bool is(0);
        int i(1);
        do
        {
            cout << v[i] << endl;
            cin >> is;
            i++;
        } while (!is and i < 1e6);
    }
}

void altSolve()
{
    int t; cin>>t;
    while(t--)
    {
        for(int i(1); i<=1e3; i++)
        {
            cout<<i*i<<endl;

            int ans; cin>>ans;
            if(ans==1) goto end;
        }
end:
        continue;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    altSolve();
    //solve();
}
