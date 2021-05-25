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
    set<string> s;//stores values in sorted order
    s.insert("abc");      
    s.insert("skdfjasf");  //log(n);
    s.insert("bcd");      
    // only unique elements are inserted in a set

    auto it = s.find("abc"); //log(n);

    if(it != s.end())
        s.erase(it);

    print(s);
}
