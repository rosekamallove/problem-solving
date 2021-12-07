#include<iostream>
using namespace std;

int main()
{
    string s, t; cin>>s>>t;
    int position(0);

    for(int i=0; i<t.size(); i++)
        if(s[position]==t[i])
            position++;

    cout<<position+1<<endl;
}
