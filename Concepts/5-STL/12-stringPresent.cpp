#include<bits/stdc++.h>
using namespace std;

/*
 * Given N strings and Q queries.
 * In each queary you are given a string
 * print yes if string is present else print no.
 *
 * N <= 1e6
 * |s| <= 100
 * Q <= 1e6
 */

int main()
{
    unordered_set<string> s;
    int n,q; cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        string temp; cin>>temp;
        s.insert(temp);
    }
    while(q--)
    {
        string temp; cin>>temp;

        auto it = s.find(temp); 
        if(it != s.end())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
}
