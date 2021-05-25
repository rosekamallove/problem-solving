#include<iostream>
using namespace std;

int main()
{
    string s; cin>>s;

    for(int i=0; i<s.size(); i++)
    {
        if(
           s[i] == 'A' or s[i] == 'O' or s[i] == 'Y' or s[i] == 'E' or s[i] == 'U' or s[i] == 'I' or 
           s[i] == 'a' or s[i] == 'o' or s[i] == 'y' or s[i] == 'e' or s[i] == 'u' or s[i] == 'i'
          )
        {
            s[i] = '.';
        }
    }
    cout<<s<<endl;
}
