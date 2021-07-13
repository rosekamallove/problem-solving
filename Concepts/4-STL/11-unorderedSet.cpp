#include<bits/stdc++.h>
using namespace std;

void print(set<string> &s)
{
    for(string value : s)
        cout<<value<<endl;

    for(auto it = s.begin(); it != s.end(); ++it)
        cout<<(*it)<<endl;
}

int main()
{
    unordered_set<string> s;//stores values in unsorted order
    s.insert("abc");      
    s.insert("skdfjasf");  //(1);
    s.insert("bcd");      

    auto it = s.find("abc"); //(1);

    if(it != s.end())
        s.erase(it);

    print(s);
}
