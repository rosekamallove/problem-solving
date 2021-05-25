#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    string s; cin>>s;
    int n = s.size();

    vector<char> v;

    for(int i=0; i<=n; i++)
    {
        if(i==0)
            v.push_back(s[i]);
        else if(i%2==0)
            v.push_back(s[i]);
    }

    sort(v.begin(),v.end());

    int size = v.size();

    for(int i=0; i<size; i++)
    {
        if(i==size-1)
            cout<<v[i];
        else
            cout<<v[i]<<'+';
    }
    cout<<endl;

}
