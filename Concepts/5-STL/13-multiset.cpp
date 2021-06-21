#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<string> s;
    s.insert("abc"); //O(log(n));

    s.insert("abc");//allows duplicates

    auto it = s.find("abc"); //O(log(n));
    //s.find() in multiset returns the iterator of the first instance of an duplicate entry

    cout<<(*it)<<endl;
}
