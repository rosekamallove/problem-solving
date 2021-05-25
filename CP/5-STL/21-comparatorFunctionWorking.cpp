#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first != a.second) 
        return a.first < b.first;
    return a.second < a.first;
}

int main()
{
    int n; cin>>n;
    vector<pair<int,int>> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i].first >> a[i].second;

    sort(a.begin(), a.end(), cmp);

    for(int i=0; i<n; i++)
        cout<<a[i].first<<' '<<a[i].second<<endl;
}

bool shouldISwap(int a, int b)
{
    if(a > b)
        return 1;
    else
        return 0;
}

void comparatorWorking()
{
    int n; cin>>n;
    vector<pair<int,int>> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i].first >> a[i].second;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(shouldISwap(a[i], a[j]))
                swap(a[i], a[j]);

    for(int i=0; i<n; i++)
        cout<<a[i].first<<' '<<a[i].second<<endl;
}

bool shouldISwap(pair<int,int> a, pair<int,int> b)
{
    /*
    if(a.first != b.first)
    {
        if(a.first > b.first)
            return 0;
        return 1;
    }
    else
    {
        if(a.second < b.second) 
            return 0;
        return 1;
    }
    */

//  => Better Way to write it:
    if(a.first != a.second) 
        return a.first < b.first;
    return a.second < a.first;
}

























