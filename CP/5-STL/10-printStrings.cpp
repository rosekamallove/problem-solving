#include<bits/stdc++.h>
using namespace std;

/*
 * Given N strings, print unique strings
 * in lexiographical order
 * n<=1e5
 * |s| <= 1e5
 */

int main()
{
    set<string> s;
    int n; cin>>n;

    for(int i=0; i<n; i++)
    {
        string temp; cin>>temp;
        s.insert(temp);
    }

    for(string temp : s)
        cout<<temp<<endl;
}
